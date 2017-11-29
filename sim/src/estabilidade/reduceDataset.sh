#!/bin/sh

awk 'NR % 50 == 0' $1 > $2
