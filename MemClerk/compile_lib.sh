#!/bin/bash

 find src -name "*.cpp" | while read file; do
    g++ -Iinclude -c "$file" -o "./build/bin/$(basename "$file" .cpp).o"
done

ar rcs ./build/libMemClerk.a ./build/bin/*.o

rm -r ../Sandbox/include
cp -r include ../Sandbox/
