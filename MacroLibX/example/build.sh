#!/bin/bash

if [ $(uname -s) = 'Darwin' ]; then
	clang main.c ../libmlx.dylib -L /opt/homebrew/lib -lSDL2 -g;
else
	clang main.c ../libmlx.so -lSDL2 -g;
fi

