#include<stdio.h>
#include<string.h>
#include"time.h"    //for clock
#include<stdlib.h>
#include<stdarg.h>
#include<LPC214X.H>  //using ARM controller fot the task
#include<curl/curl.h>//this is the header file to download from url that contains all the functions for this program
extern void io_write(int port,int pin,int value);
extern void io_dir(int port,int pin,int direction);
extern int io_read(int port,int pin);



//for this task we need to interface lpc2148 to pc by rs232 terminal
//we need to debug it by using keil compiler
