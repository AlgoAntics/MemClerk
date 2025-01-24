#!/bin/bash

g++ $(find src -name "*.cpp") ../MemClerk/build/libMemClerk.a -o ./build/sandbox
