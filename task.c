#include"header.h"
int main(int argc,char **argv) 
{	
    FILE *fp = fopen(argv[1],"r");//opening the storage file that downloaded drom the url in read mode
    char name[20],s[20]; 
    int count;
    int ID[0];
    clock_t start,end;//clock_t for the value returned in the cpu-time speed
    printf("Enter the name to search:\n");
    scanf("%s",name);
    while(fscanf(fp,"%s",s)!=-1)//fetching the strings one by one from storage file
    {
        count++;
        //clock(),it returns the no.of clock ticks for a function 
        start = clock(); //recording the starting tick 
        if(strcmp(s,name)==0) //comparing the scanned name
        {
            end =clock(); //if true it will end the clock  
            break;      //comes out of the wile loop
        }
    }
    //CLOCKS_PER_SEC to be divided to get the no.of seconds used
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    printf("ID=%d",ID[count]);//prints the  id related to name
    printf("time_taken= %lf",time_taken);//prints the query time taken for a function to execute
}

//we need to pass 2 arguments
//./filename storage/emulated/0/Download/filename.c
