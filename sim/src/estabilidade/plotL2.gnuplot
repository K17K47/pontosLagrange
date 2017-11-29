set terminal png size 600,600 enhanced font 'Verdana,14'
set size ratio -1
set size square
set xrange[-1.25e6:1.25e6]
set yrange[-1.25e6:1.25e6]
plot 'out' using 1:2 with lines title 'M1', 'out' using 3:4 with lines title 'M2', 'out' using 7:8 with lines title 'P2'
