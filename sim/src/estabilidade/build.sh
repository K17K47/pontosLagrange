#!/bin/sh

g++ main.cpp -o main -Wall -I../../physicsFrmwk/src -L../../physicsFrmwk/build/src/.libs -fPIC -std=c++11 -lphysics -pthread
