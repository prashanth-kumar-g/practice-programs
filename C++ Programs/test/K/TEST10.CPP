#include<iostream>

int main()
{
 int a[5][2],i,j,col,count=0;
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
  for(j=0;j<2;j++)
  {
   if(a[i][j]==a[j][i])
   {
    count=0;

   }
   else
   {
    count++;
   }
  }
}
 cout<<"\ncount = "<<count;
 return 0;
}