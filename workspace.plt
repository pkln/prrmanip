set terminal png enhanced size 1000 1000 fname "Times" fsize 5
set output "workspace.png"
set title "Workspace of PRR Manipulator"
set xlabel "X"
set ylabel "Y"
plot "./triangle.dat" u 1:2:3 with lines palette title ""
plot "./workspace.dat" u 1:2:3 with points palette title ""
