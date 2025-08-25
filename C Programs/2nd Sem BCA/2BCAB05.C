/*program for pattern matching for two strings*/
#include<stdio.h>

#include<string.h>
int main()
{
 int i,j;
 int m,n;
 char pat[20],txt[20];
 
 printf("\nEnter the string : ");
 scanf("%s",&txt);
 printf("Enter the pattern : ");
 scanf("%s",&pat);
 m=strlen(pat);
 n=strlen(txt);
 for(i=0;i<=n-m;i++)
 {
  for(j=0;j<m;j++)
  if(txt[i+j]!=pat[j])
  break;
  if(j==m)
  printf("pattern matches at index : %d",i);
 }
 return 0;
}














