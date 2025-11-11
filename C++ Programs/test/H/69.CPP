// program for class template
#include<iostream>

template<class T>
class vector
{
 public : T *arr;
	  T size;
	  vector(T s)
	  {
	   size = s;
	   arr = new T[size];
	  }
	  T dotProduct(vector &v)
	  {
	   T d=0;
	   for(int i=0;i<size;i++)
	   {
	    d=d+arr[i]*v.arr[i];
	   }
	   return d;
	  }
};
int main()
{
 clrscr();
 int choice,size;
 cout<<"\nWhich type for dotProduct (int-1, float-2, double-3) : ";
 cin>>choice;
 cout<<"\nEnter the size : ";
 cin>>size;
 // here switch case is used, u can use if-else also
 switch(choice)
 {
  case 1 : vector<int>v1(size);
	   vector<int>v2(size);
	   cout<<"\nEnter 1st array elements : ";
	   for(int i=0;i<size;i++)
	   {
	    cin>>v1.arr[i];
	   }
	   cout<<"\nEnter 2nd array elements : ";
	   for(i=0;i<size;i++)
	   {
	    cin>>v2.arr[i];
	   }
	   int res1 = v1.dotProduct(v2);
	   cout<<"\nDot Product of 2 array elements is : "<<res1;
	   break;
  case 2 : vector<float>w1(size);
	   vector<float>w2(size);
	   cout<<"\nEnter 1st array elements : ";
	   for(i=0;i<size;i++)
	   {
	    cin>>w1.arr[i];
	   }
	   cout<<"\nEnter 2nd array elements : ";
	   for(i=0;i<size;i++)
	   {
	    cin>>w2.arr[i];
	   }
	   float res2 = w1.dotProduct(w2);
	   cout<<"\nDot Product of 2 array elements is : "<<res2;
	   break;
  case 3 : vector<double>x1(size);
	   vector<double>x2(size);
	   cout<<"\nEnter 1st array elements : ";
	   for(i=0;i<size;i++)
	   {
	    cin>>x1.arr[i];
	   }
	   cout<<"\nEnter 2nd array elements : ";
	   for(i=0;i<size;i++)
	   {
	    cin>>x2.arr[i];
	   }
	   double res3 = x1.dotProduct(x2);
	   cout<<"\nDot Product of 2 array elements is : "<<res3;
	   break;
  default : cout<<"\nInvalid Choice";
 }
 return 0;
}