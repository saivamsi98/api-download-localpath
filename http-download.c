#include"header.h"
#define SWR 16//port0.16
#define SW 1//port0.1
int main(int argc,char **argv)
{
    io_dir(PORT0,SWR,OUTPUT);//port0.16 is output pin
    io_dir(PORT0,SW,INPUT);//port0.1 is input pin
    CURL *curl;  //creating curl handler,will be responsible for all n/w functions in this program
    FILE *fp;   //declaring a file pointer
    int result;
    if(io_read(PORT0,SW)==0)//is switch is pressed it enters the task and reads the latest data from url
    {
    fp=fopen(argv[2],"wb"); //opening the destination path in write binary,to store the data that downloaded
    
    curl = curl_easy_init(); //initiallizing curl
    //after curl initiallization,we can configure it by below functions 
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]); //CURLOPT_URL allows us to download from url

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); //CURLOPT_WRITEDATA this tells where to store the downloaded data

    //curl library by default doesn't consider http errors as real error 
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);//for fixing http errors we are setting CURLOPT_FAILONERROR to 1
    }
    result = curl_easy_perform(curl); //this function returns an integer that download is succesfull or not
    
    if(result == CURLE_OK) //if suuccess it prints if data 
    printf("download succesfull:\n");
    else
    printf("Error: %s\n", curl_easy_strerror(result)); // if condition fails it will returns a string indicating type of error
    
    fclose(fp);//closing the file 
    
    curl_easy_cleanup(curl);//releasing all the resources that the curl handler holding
}



//for compiling we need to give 3 arguments
//./filename http://demo4657392.mockable.io/list-tag-ids /storage/emulated/0/Download/filename.c
