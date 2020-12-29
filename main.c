#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>

//the header file we defined
#include "func.h"
#include "music.h"
#include "contentf.h"

void getNames(char []); //function that is the heart of the program
char * gettExtension(char *); //separate extension from file name
char * getCmd(char[],char[],char[]);//generate a command that could be understand by the O/S
int directory_exist(char[],char[]);//checks weather a folder exist or not
int searchFordot(char []);//to find a dot in a file name

char filepath[400];
int countfiles;

char * gettExtension(char *fullname)
{
    char* ext1;
    ext1 = strrchr(fullname,'.');
    return ext1+1;
}

char *getCmd(char filename[],char ext[],char final_cmd[])
{
    strcat(final_cmd,"mkdir ");
    strcat(final_cmd,ext);
    char cmd2[400]=" && move ";
    char finalfilename[400]="\"";

    strcat(finalfilename,filename);
    strcat(finalfilename,"\"");

    strcat(cmd2,finalfilename);
    strcat(cmd2," ");
    strcat(cmd2,ext);
    strcat(final_cmd,cmd2);
    return final_cmd;

}
int searchFordot(char filename[])
{
    int i=0;
    while(i<strlen(filename)){
        if(filename[i]=='.') return 1;
        else i++;
    }
    return 0;
}

int searchForSpace(char filename[])
{
    int i=0;
    while(i<strlen(filename))
    {
        if(filename[i]=='.') return 1;
        else i++;
    }
    return 0;
}
//hello

void getNames(char filepath[]){
    DIR *d;
    struct dirent *dir;
    d = opendir(filepath);
    char final_cmd[1000]="";

    if (d)
    {
     while ((dir = readdir(d)) != NULL)
        {
            int dx;
            int size=strlen(dir->d_name);
            char filename[size+10];
            char *ext;

            strcpy(filename,dir->d_name);
         


int main(int argc, char* argv[])
{
   clock_t t;
    t = clock();
   strcpy(filepath,intilizeitall(argc,argv));
   printf("the path of file is %s",filepath);
   getNames(filepath);
 t = clock() - t;

   double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

   printf("fun() took %f seconds to execute  %d number of files \n", time_taken,countfiles);

   return(0);
}
