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

