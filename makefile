Outfile : header.o task.o http-download.o driverforARM.o
          cc header.o task.o http-download.o driverforARM.o
header.o : header.c
           cc -c header.c
task.o : task.c
         cc -c task.c
http-download.o : http-download.c
                  cc -c http-download.c
driverforARM.o : driverforARM.c
                 cc -c driverforARM.c
