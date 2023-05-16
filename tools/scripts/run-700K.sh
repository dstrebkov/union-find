#!/usr/bin/env bash

BINARY=../../build-union-find-Desktop_Qt_6_5_0_GCC_64bit-Release/app-union-find/app-union-find
FILE=../../union-find-algs/test/test-data/uf_700K.txt

echo "Running QuickUnion:"
echo -e "QuickUnion\n$(cat $FILE)" > ./to_stdin.txt
$BINARY < ./to_stdin.txt
rm ./to_stdin.txt

echo "Running WeightedQuickUnion:"
echo -e "WeightedQuickUnion\n$(cat $FILE)" > ./to_stdin.txt
$BINARY < ./to_stdin.txt
#rm ./to_stdin.txt
