#!/bin/sh

mencoder mf://@list.txt -mf w=768:h=768:fps=60:type=png -ovc lavc -lavcopts vcodec=mpeg4:mbd=2:trell -oac copy -o output.avi
