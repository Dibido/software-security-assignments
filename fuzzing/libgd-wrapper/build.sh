#!/usr/bin/env bash

CC=clang
CXX=clang++


DIR=$(pwd)
echo $DIR

SAN_ARG=

if [ $# -lt 2 ]; then
    echo Please specify a fuzzer and whether to use Asan.
else
    case "$1" in
        "afl")
            echo Using fuzzer AFL.
            CC=afl-cc
            CXX=afl-c++
            AFL_C_ARGS=
            ;;
        "n")
            echo Using default compiler $CC/$CXX.
            ;;
        *)
            echo Specified fuzzer $1 is not supported, using default compiler $CC/$CXX instead.
            ;;
    esac
    if [ "$2" = "y" ]; then
        echo Using Asan.
        # SAN_SUPPR_DIR="$DIR/suppression.supp"
        # SAN_ARG="-fsanitize=address -fsanitize-blacklist=$SAN_SUPPR_DIR -detect_leaks=false -fno-omit-frame-pointer -DEBUG"
        SAN_ARG="-fsanitize=address"

    else
        echo Not using Asan.
    fi
fi

cd libgd
./cmake/distclean.sh
cmake CMakeLists.txt -DCMAKE_C_COMPILER=$CC -DCMAKE_CXX_COMPILER=$CXX -DCMAKE_C_FLAGS="$SAN_ARG" -DCMAKE_CXX_FLAGS="$SAN_ARG"
make
cd ..

rm wrapper
$CC $SAN_ARG -o wrapper main.c libgd/Bin/libgd.so -lm