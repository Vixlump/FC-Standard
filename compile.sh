#!/bin/sh
./VersionUtil
g++ dev.cpp -std=c++17 -pthread -lGL -lglut -lGLU -lGLEW -lX11 -lcurl -o Build/FC -O3
echo Compile Script Has Ended!
