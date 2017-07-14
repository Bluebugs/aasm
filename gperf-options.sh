#!/bin/sh

echo -n `grep +options+ $1| cut -f 3- -d +`
