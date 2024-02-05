#!/bin/bash

libs=-luser32
warnings=-Wno-writeable-strings
clang -g src/main.cpp -o Celeste.exe $libs $warnings
#Build settings for the application, build shorthand is CTRL + SHIFT + B