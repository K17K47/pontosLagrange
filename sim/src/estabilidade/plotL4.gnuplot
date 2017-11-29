set terminal png size 1024,1024 enhanced font 'Verdana,10'
set size ratio -1
set size square
set xrange[-1.5e6:1.5e6]
set yrange[-1.5e6:1.5e6]
plot 'out' using 1:2 with lines title 'M1', 'out' using 3:4 with lines title 'M2', 'out' using 11:12 with lines title 'Particle'
