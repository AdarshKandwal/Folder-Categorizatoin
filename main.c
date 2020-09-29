#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <errno.h>

//the header file we defined

#include "func.h"

void getNames(char []); //function that is the heart of the program
char * gettExtension(char *); //separate extension from file name
char * getCmd(char[],char[],char[]);//generate a command that could be understand by the O/S
int directory_exist(char[],char[]);//checks weather a folder exist or not
int searchFordot(char []);//to find a dot in a file name

char filepath[800];



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
    char finalfilename[500]="\"";

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

int directory_exist(char file[],char ext[])
{
    char temp[600];

    strcpy(temp,file);
    strcat(temp,"\\");
    strcat(temp,ext);

    DIR* dir = opendir(temp);

    if (dir)
    {
        closedir(dir);
        return 1;
    }
    else if (ENOENT == errno)
    {
        return 0;
    }
    else
    {
        return 2;
    }

}


char *pathcreation(char filepath[],char ext2[],char temp[]){
            strcpy(temp,filepath);
            strcat(temp,"\\");
            strcat(temp,ext2);
            return temp;
            //int dx=directory_exist(temp,ext);
}


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


            if(strcmpi(filename,".")==0||strcmpi(filename,"..")==0)continue;

            if (searchFordot(filename)==1)
            {
                ext=gettExtension(filename);
                dx=directory_exist(filepath,ext);
                printf("\n%d %s\n",dx,filename);
            }
            else
            {
               ext=NULL;
               printf("\n%s\n",filename);
               continue;
            }

            chdir(filepath);

             if(!dx)
            {

                if(strcmpi(ext,"xlsx")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }

                if(strcmpi(ext,"pdf")==0)
                {
                    strcpy(final_cmd," ");
                    char *temp=getCmd(filename,ext,final_cmd);

                    system(temp);
                }

                if(strcmpi(ext,"jpg")==0 || strcmpi(ext,"jpeg")==0)
                {
                    strcpy(final_cmd," ");
                    char *temp=getCmd(filename,ext,final_cmd);

                    system(temp);

                }

                if(strcmpi(ext,"ipynb")==0)
                {
                    strcpy(final_cmd," ");
                    char *temp=getCmd(filename,ext,final_cmd);

                    system(temp);
                }

                if(strcmpi(ext,"pptx")==0)
                {
                   strcpy(final_cmd,"");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);

                }

                if(strcmpi(ext,"docx")==0)
                {
                    strcpy(final_cmd,"");
                    char *temp=getCmd(filename,ext,final_cmd);

                    system(temp);
                }
                //Audio file formats extensions
                if(strcmpi(ext,"aif")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cda")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"mid") || strcmpi(ext,"midi")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"mp3")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }if(strcmpi(ext,"mpa")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ogg")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"wav")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"wma")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"wpl")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Compressed file extensions
                if(strcmpi(ext,"7z")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"arj")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"deb")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"pkg")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"rar")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"rpm")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"tar.gz")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"z")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"zip")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Disc and media file extensions
                if(strcmpi(ext,"bin")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"dmg")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"iso")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"toast")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"vcd")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Data and database file extensions
                if(strcmpi(ext,"csv")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"dat")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"db") || (strcmpi(ext,"dbf")==0))
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"log")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }if(strcmpi(ext,"mdb")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"sav")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"sql")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"tar")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"xml")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //E-mail file extensions
                if(strcmpi(ext,"email")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"eml")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"emlx")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"msg")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"oft")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ost")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"pst")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"vcf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Executable file extensions
                if(strcmpi(ext,"apk")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"bat")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"bin")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cgi") || (strcmpi(ext,"pl")==0))
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"com")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"exe")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"gadget")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"jar")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"msi")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"py")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"wsf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Font file extensions
                if(strcmpi(ext,"fnt")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"fon")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"otf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ttf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Image file formats by file extension
                if(strcmpi(ext,"ai")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"bmp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"gif")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ico")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }

                if(strcmpi(ext,"jpg")==0 || strcmpi(ext,"jpeg")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }

                if(strcmpi(ext,"png")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ps")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"psd")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"svg")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"tif") || strcmpi(ext,"tiff")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Internet related file extensions
                if(strcmpi(ext,"asp") || (strcmpi(ext,"aspx")==0))
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cer")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cfm")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cgi") || (strcmpi(ext,"pl")==0))
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"css")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"html") || strcmpi(ext,"htm")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"js")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"jsp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"part")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"php")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"py")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"rss")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"rss")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"xhtml")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Presentation file formats file extension
                if(strcmpi(ext,"key")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"odp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"pps")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ppt")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"pptx")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Programming files extensions
                if(strcmpi(ext,"c")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cgi")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"class")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cpp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cs")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"h")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"java")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"php")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"py")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"sh")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"swift")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"vb")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Spreadsheet file formats file extension
                if(strcmpi(ext,"ods")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"xls")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"xlsm")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"xlsx")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //System related file formats file extensions
                if(strcmpi(ext,"bak")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cab")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cfb")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cpl")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"cur")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"dll")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"dmp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"drv")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"icns")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ico")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"ini")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"lnk")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"msi")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"sys")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"tmp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Video file formats file extension
                if(strcmpi(ext,"3g2")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"3gp")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"avi")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"flv")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"h264")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"m4v")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"mkv")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"mov")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"mp4")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"mpg") || (strcmpi(ext,"mpeg")==0))
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"rm")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"swf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"vob")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"wmv")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                //Word processor and text file formats file extension
                if(strcmpi(ext,"doc") || (strcmpi(ext,"docx")==0))
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"odt")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"pdf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"rtf")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"tex")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"txt")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
                if(strcmpi(ext,"wpd")==0)
                {
                   strcpy(final_cmd," ");
                   char *temp=getCmd(filename,ext,final_cmd);

                   system(temp);
                }
            }

            else
            {
                char cmd[60]="move ";
                char finalfilename[50]="\"";
                strcat(finalfilename,filename);
                strcat(finalfilename,"\"");

                strcat(cmd,finalfilename);
                strcat(cmd," ");
                strcat(cmd,ext);
                system(cmd);
            }
        }
        closedir(d);

    }
}

int main(int argc, char* argv[])
{
   strcpy(filepath,intilizeitall(argc,argv));
   printf("the path of file is %s",filepath);
   getNames(filepath);

   return(0);

}
