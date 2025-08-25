//program to sort elements using templates
#include<iostream>

template<class S>
void bubble(S a[],int n)
{
 int i,j;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(a[j]>a[j+1])
   {
    swap(a[j],a[j+1]);
   }
  }
 }
}
template<class T>
void swap(T &x,T &y)
{
 T temp;
 temp=x;
 x=y;
 y=temp;
}
int main()
{
 int i,n,d[10];
 float f[10];
 char c[10];
 clrscr();
 cout<<"\nEnter the size of the array : ";
 cin>>n;
 cout<<"Enter the elements of integer array : ";
 for(i=1;i<=n;i++)
 cin>>d[i];
 cout<<"Enter the elements of float array : ";
 for(i=1;i<=n;i++)
 cin>>f[i];
 cout<<"Enter the elements of character array : ";
 for(i=1;i<=n;i++)
 cin>>c[i];
 cout<<"\n";
// cout.precision(2);
 cout<<"\nOriginal integer array : ";
 for(i=1;i<=n;i++)
 cout<<d[i]<<"  ";
 cout<<"\nOriginal float array : ";
 for(i=1;i<=n;i++)
 cout<<f[i]<<"  ";
 cout<<"\nOriginal character array : ";
 for(i=1;i<=n;i++)
 cout<<c[i]<<"  ";
 bubble(d,n);
 cout<<"\n\nSorted integer array :  ";
 for(i=1;i<=n;i++)
 cout<<d[i]<<"  ";
 bubble(f,n);
 cout<<"\nSorted float array :  ";
 for(i=1;i<=n;i++)
 cout<<f[i]<<"  ";
 bubble(c,n+1);
 cout<<"\nSorted character array :  ";
 for(i=1;i<=n;i++)
 cout<<c[i]<<"  ";
 return 0;
}