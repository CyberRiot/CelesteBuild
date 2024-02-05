#!/bin/bash

libs=-luser32
warnings=-Wno-writeable-strings
clang -g src/main.cpp -o Celeste.exe $libs $warnings