#!/bin/bash
clang++ -std=c++17 -D MAC *.cpp -g -I/usr/local/include -o prog `sdl2-config --cflags --libs` -lSDL2_ttf
