#!/bin/sh
./VersionUtil
g++ dev.cpp -std=c++17 -pthread -o Build/FC -O3
echo Compile Script Has Ended!
