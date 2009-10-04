#!/bin/bash

#
# AASM test script
# (C) Alexandre Becoulet 2003
#

case "$1" in
    
    empty)

	for i in $2 ; do
	    test -f "$i" || continue

	    src="${i%.*}"

	    for j in $3 ; do
		test -f "$j" || continue

		. $j

		echo -n "empty" > "$src.$TEST_NAME.ok"
		printf "%10s : %-50s %10s" "$TEST_NAME" "$src.$TEST_NAME.ok" empty
		echo
	    done
	done

	;;

    ref)
	echo "testing..."
	
	if ! "$0" test ; then
	    echo "Obsolete test reference files have to be empty before doing ref"
	    exit 1
	fi

	echo "creating ref files..."

	for test_file in *.test ; do
	    . $test_file || continue

	    for i in tests_*/*.$TEST_NAME.ok ; do

		test -f "$i" || continue
		test "$(cat $i)" = "empty" || continue

		#cat -n "${i%$TEST_NAME.ok}aam" > "${i}"

		${AASM_BIN:-aasm} $AASM_PARAM "${i%$TEST_NAME.ok}aam" > "${i}"

		if test -f "${i%.$TEST_NAME.ok}$AASM_OUT_EXT" ; then
		    "$TEST_BIN" $TEST_BIN_PARAM "${i%.$TEST_NAME.ok}$AASM_OUT_EXT" >> "${i}"
		else
		    if test -f "${i%.$TEST_NAME.ok}$AASM_OUT_EXT2" ; then
			"$TEST_BIN" $TEST_BIN_PARAM "${i%.$TEST_NAME.ok}$AASM_OUT_EXT2" >> "${i}"
		    else
			echo -n >> "${i}"
		    fi
		fi

		printf "%10s : %-50s %10s" "$TEST_NAME" "$i" "ref done"
		echo
	    done
	done
	;;

    test)
	
	FAILED=0
	COUNT=0

	for test_file in *.test ; do
	    . $test_file || continue

	    if ! test -x "`which $TEST_BIN`" ; then
		printf "%10s : %-50s %10s" "$TEST_NAME" "$TEST_BIN" MISSING
		echo
		continue
	    fi

	    for i in tests_*/*.$TEST_NAME.ok ; do

		test -f "$i" || continue

		test "$(cat $i)" = "empty" && continue

		#cat -n "${i%$TEST_NAME.ok}aam" > "${i%.ok}"
		
		${AASM_BIN:-aasm} $AASM_PARAM "${i%$TEST_NAME.ok}aam" > "${i%.ok}"

		if test -f "${i%.$TEST_NAME.ok}$AASM_OUT_EXT" ; then
		    "$TEST_BIN" $TEST_BIN_PARAM "${i%.$TEST_NAME.ok}$AASM_OUT_EXT" >> "${i%.ok}"
		else
		    if test -f "${i%.$TEST_NAME.ok}$AASM_OUT_EXT2" ; then
			"$TEST_BIN" $TEST_BIN_PARAM "${i%.$TEST_NAME.ok}$AASM_OUT_EXT2" >> "${i%.ok}"
		    else
			echo -n >> "${i%.ok}"
		    fi
		fi

		if ! diff "$i" "${i%.ok}" ; then
		    printf "%10s : %-50s %10s" "$TEST_NAME" "$i" FAILED
		    FAILED=$((FAILED+1))
		else
		    printf "%10s : %-50s %10s" "$TEST_NAME" "$i" passed
		    rm -f "${i%.ok}" "${i%.$TEST_NAME.ok}$AASM_OUT_EXT"
		fi
		echo

		COUNT=$((COUNT+1))

	    done
	    for i in  $AASM_OUT_CLEAN ; do rm -f tests_*/$i ; done

	done

	echo
	echo "    $FAILED / $COUNT test(s) failed"

	exit $FAILED
	;;

    *)

	echo "usage: $0 [test | ref | empty sourcefile.aam testfile.test]"
	;;

esac

exit 0

