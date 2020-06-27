Outfile : header.o task.o http-download.o
          cc header.o task.o http-download.o
header.o : header.c
           cc -c header.c
task.o : task.c
         cc -c task.c
http-download.o : http-download.c
                  cc -c http-download.c
