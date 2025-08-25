// program to print symbol of (1-5) dimension
#include<iostream>

int main()
{
 int x,choice;
 char ch;
 clrscr();
 cout<<"\nEnter the symbol : ";
 cin>>ch;
 cout<<"Enter the size : ";
 cin>>x;
 cout<<"Enter your choice (1-5) : ";
 cin>>choice;
 cout<<"\n";

 switch(choice)
 {
  case 1 : for(int i=1;i<=x;i++)
	   {
	    cout<<ch<<" ";
	   }
	   break;

  case 2 : for(i=1;i<=x;i++)
	   {
	    for(int j=1;j<=i;j++)
	    {
	     cout<<ch<<" ";
	    }
	    cout<<"\n";
	   }
	   break;

  case 3 : for(i=1;i<=x;i++)
	   {
	    for(int j=1;j<=i;j++)
	    {
	     for(int k=1;k<=j;k++)
	     {
	      cout<<ch<<" ";
	     }
	     cout<<"\n";
	    }
	    cout<<"\n";
	   }
	   break;

  case 4 : for(i=1;i<=x;i++)
	   {
	    for(int j=1;j<=i;j++)
	    {
	     for(int k=1;k<=j;k++)
	     {
	      for(int l=1;l<=k;l++)
	      {
	       cout<<ch<<" ";
	      }
	      cout<<"\n";
	     }
	     cout<<"\n";
	    }
	    cout<<"\n";
	   }
	   break;

  case 5 : for(i=1;i<=x;i++)
	   {
	    for(int j=1;j<=i;j++)
	    {
	     for(int k=1;k<=j;k++)
	     {
	      for(int l=1;l<=k;l++)
	      {
	       for(int m=1;m<=l;m++)
	       {
		cout<<ch<<" ";
	       }
	       cout<<"\n";
	      }
	      cout<<"\n";
	     }
	     cout<<"\n";
	    }
	    cout<<"\n";
	   }
	   break;

  default : cout<<"Invalid Choice";
 }

 return 0;
}