/*program to copy content of one file to another file*/
#include<stdio.h>

int main()
{
 FILE *fs,*fd;
 char ch,src[13],des[13];
 
 printf("\n***** File Copy Program *****\n");
 printf("\nEnter the source file name\n");
 scanf("%s",src);
 fs=fopen(src,"r");
 if(fs==NULL)
 {
  printf("\nFile does not exist or cannot open\n");
  return 0;
  exit(0);
 }
 printf("Enter the destination file name\n");
 scanf("%s",des);
 fd=fopen(des,"w");
 if(fd==NULL)
 {
  printf("\nFile does not exist or cannot open\n");
  fclose(fs);
  return 0;
 }
 while(1)
 {
  ch=fgetc(fs);
  if(ch==EOF)
   break;
  else
   putc(ch,fd);
 }
 printf("File copy successful from %s to %s",src,des);
 fclose(fs);
 fclose(fd);
 return 0;
}