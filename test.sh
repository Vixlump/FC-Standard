#!/bin/sh
g++ dev.cpp -std=c++17 -pthread -lGL -lglut -lGLU -lGLEW -lX11 -lcurl -o Build/FC
echo Compile Script Has Ended!
