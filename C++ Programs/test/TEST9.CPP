#include<iostream>

int main()
{
 int a[5][2],x=1,y,n,i,j,k,c=0,temp,u=0,col;
 clrscr();
 cout<<"\nEnter number of lines : ";
 cin>>col;
 cout<<"\nEnter coordinates : \n";
 for(i=0;i<col;i++)
 {
  for(j=0;j<2;j++)
  {
   cin>>a[i][j];
  }
 }

 for(i=0;i<col;i++)
 {
  c=0;
  x=0;
  for(j=0;j<2;j++)
  {
   temp=a[i][j];
   (j==0)?y=1:y=0;
   for(k=x;k<col;k++)
   {
    if(temp==a[k][y])
    {
     c++;
    }
   }
  }
  x++;
  if(c>=2)
  {
   u++;
  }
 }
 cout<<"\n"<<col-u;

 return 0;
}