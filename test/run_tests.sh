#!/bin/sh
declare -i testcount=0
declare -i failedcount=0
for file in tests/*.c
do
	testname=$(echo $file | cut -d'/' -f2 | cut -d'.' -f1)
	echo "[\033[36m$testname\033[0m]"
	echo "std:"
	./bins/std_$testname | tee std_result
	echo "ft:"
	./bins/own_$testname | tee own_result
	if [ "$(diff std_result own_result)" = "" ]
	then
		echo "[\033[32mPASS\033[0m]"
	else
		echo "[\033[31mFAIL\033[0m]"
		failedcount=$(( failedcount + 1 ))
	fi
		echo "_____________________________________"
			testcount=$(( testcount + 1 ))
done
if [ $failedcount != 0 ]
then
	echo "\033[31mTESTING DONE, FAILED $failedcount TESTS ON $testcount TOTAL\033[0m"
else
	echo "\033[32mTESTING DONE, ALL $testcount TESTS PASSED\033[0m"
fi
