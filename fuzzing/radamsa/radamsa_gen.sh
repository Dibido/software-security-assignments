#!/bin/bash
TEST_CASES_PER_SEED_FILE=500
SEED=4

if [ $# -lt 1 ]; then
    echo "Please specify a path (pattern) for the seed files."
    echo "Make sure to include the file extension, e.g.:"
    echo "  ../seeds/*.bmp"
else
    test_case_num=0
    for seed_file in "$1"; do
        radamsa --seed $SEED --count $TEST_CASES_PER_SEED_FILE -o generated_tests/testcase-$test_case_num-mutation-%n.%s $seed_file
        echo "Radamsa is done generating tests for test case $test_case_num".
        test_case_num=$((test_case_num + 1))
    done
fi