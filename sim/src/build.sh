#!/bin/sh

g++ pontosLagrange.cpp -o pontosLagrange -Wall -I../physicsFrmwk/src -L../physicsFrmwk/build/src/.libs -fPIC -std=c++11 -lphysics -pthread
