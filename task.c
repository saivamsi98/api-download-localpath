#include"header.h"
int main(int argc,char **argv) 
{	
    int i,len,temp;
    FILE *fp = fopen(argv[1],"r");//opening the storage file that downloaded drom the url in read mode
    char name[20],s[20],s2[20],s3[20],s4[20]; 
    
    clock_t start,end;//clock_t for the value returned in the cpu-time speed
    
    printf("Enter the name to search:\n");
    scanf("%s",name);
    
    while(fscanf(fp,"%s",s)!=-1)//fetching the strings one by one from storage file
    {
        temp=len=strlen(s);//calculating the length of fetched string
        i=0;
        //consider this example for below logic
        //"123":"Hello"
        for(;len-5;len--,i++)//to remove quotations iterating the loop 5times
            s2[i]=s[i+2];//only storing the name without quotations in array named s2
    
        //clock(),it returns the no.of clock ticks for a function 
        start = clock(); //recording the starting tick 
        if(strcmp(s2,name)==0) //comparing the scanned name
        {
            end =clock(); //if true it will end the clock  
            
            fseek(fp,-(temp-8),0);//it will move from current position to id,by neglecting all the spaces and colons
            
            fscanf(fp,"%s",s3);//now reading the data to another array named s3
            for(;s3[i]!=' ';i++)//iterating the loop until space,so that it only fetches student id
                s4[i]=s3[i+2];//storing those student ids in the array named s4
            
            break;      //comes out of the wile loop
        }
    }
    //CLOCKS_PER_SEC to be divided to get the no.of seconds used
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    printf("ID=%s",s4]);//prints the  id related to name
    printf("time_taken= %lf",time_taken);//prints the query time taken for a function to execute
}

//we need to pass 2 arguments
//./filename storage/emulated/0/Download/filename.c
