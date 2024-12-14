set xrange [-10:10]
set yrange [-10:10]
set style line 1 linecolor rgb "red" pointtype 7 pointsize 2 
plot "polygon.txt" using 1:2 with lines lc rgb "blue" title "Polygon", "points.txt" using 1:2 with points ls 1 title "Points"
