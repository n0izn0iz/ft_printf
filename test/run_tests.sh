#!/bin/zsh
declare -i testcount=0
declare -i failedcount=0
echo "\nSTARTING TESTS"
echo "________________________________________________________________________________"
for file in tests/*.c
do
	testname=$(echo $file | cut -d'/' -f2 | cut -d'.' -f1)
	echo "[\033[36m$testname\033[0m]"
	echo "\033[33m-std:\033[0m"
	./bins/std_$testname | tee std_result
	echo "\033[33m-ft:\033[0m"
	./bins/own_$testname | tee own_result
	diff_result=$(diff std_result own_result)
	if [ "$diff_result" = "" ]
	then
		echo "[\033[32mPASS\033[0m]"
	else
		echo "[\033[31mFAIL\033[0m]"
		echo "$diff_result"
		failedcount=$(( failedcount + 1 ))
	fi
		echo "________________________________________________________________________________"
			testcount=$(( testcount + 1 ))
done
if [ $failedcount != 0 ]
then
	echo "\033[31mTESTING DONE, FAILED $failedcount TESTS ON $testcount TOTAL\033[0m\n"
else
	echo "\033[32mTESTING DONE, ALL $testcount TESTS PASSED\033[0m\n"
fi
