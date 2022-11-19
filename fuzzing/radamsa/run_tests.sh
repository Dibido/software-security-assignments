#!/bin/bash
EXEC_PATH="../libgd-wrapper/wrapper"

if [ $# -lt 1 ]; then
    echo "Please specify the file extension of the test case files that are to be used."
else
    nr_of_nonzero_returns=0
    echo "Nr of non-zero return values: 0"
    for test_file in generated_tests/testcase-*-mutation-*.$1; do
        ./$EXEC_PATH $1 $test_file
        status=$?
        if [ $status != "0" ]; then
            nr_of_nonzero_returns=$((nr_of_nonzero_returns + 1))
            echo "Nr of non-zero return values: $nr_of_nonzero_returns"
        fi
    done
    echo "Nr of non-zero return values: $nr_of_nonzero_returns"
fi