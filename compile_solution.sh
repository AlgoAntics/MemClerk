#!/bin/bash

cd ./MemClerk
./compile_lib.sh

cd ../Sandbox
./compile_app.sh

cd build
cp * ../../main_build
