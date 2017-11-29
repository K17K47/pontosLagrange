set terminal png size 768,768 enhanced font 'Verdana,12'
set size ratio -1
set size square
set xrange[-1.25e6:1.25e6]
set yrange[-1.25e6:1.25e6]
do for [i=1:3600]{
   set output 'out/lagrange'.i.'.png'
   plot '../out' using 1:2 every 210000::58*i::58*i+1 title 'M1',\
        '../out' using 3:4 every 210000::58*i::58*i title 'M2',\
        '../out' using 5:6 every ::0::58*i with lines title 'P1',\
        '../out' using 7:8 every ::0::58*i with lines title 'P2',\
        '../out' using 9:10 every ::0::58*i with lines title 'P3',\
        '../out' using 11:12 every ::0::58*i with lines title 'P4',\
        '../out' using 13:14 every ::0::58*i with lines title 'P5'
}
