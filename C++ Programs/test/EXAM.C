#include<stdio.h>

int main()
{
 int choice,n,a[10],i,j,temp;
 clrscr();
 while(1)
 {
  printf("\n\n Menu");
  printf("\n 1.Bubble Sort");
  printf("\n 2.Insertion Sort");
  printf("\n 3.Selection Sort");
  printf("\n 4.Exit");
  printf("\n\n Enter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1 : printf(" Enter the limit : ");
	    scanf("%d",&n);
	    printf(" Enter the numbers : ");
	    for(i=1;i<=n;i++)
	    {
	     scanf("%d",&a[i]);
	    }
	    for(i=1;i<=n-1;i++)
	    {
	     for(j=1;j<=n-i;j++)
	     {
	      if(a[j]>a[j+1])
	      {
	       temp=a[j];
	       a[j]=a[j+1];
	       a[j+1]=temp;
	      }
	     }
	    }
	    printf(" Array after sorting : ");
	    for(i=1;i<=n;i++)
	    {
	     printf("%d ",a[i]);
	    }
	    break;
   case 2 : printf(" Enter the limit : ");
	    scanf("%d",&n);
	    printf(" Enter the numbers : ");
	    for(i=1;i<=n;i++)
	    {
	     scanf("%d",&a[i]);
	    }
	    for(i=1;i<=n-1;i++)
	    {
	     for(j=i;j>=1;j--)
	     {
	      if(a[j]>a[j+1])
	      {
	       temp=a[j];
	       a[j]=a[j+1];
	       a[j+1]=temp;
	      }
	     }
	    }
	    printf(" Array after sorting : ");
	    for(i=1;i<=n;i++)
	    {
	     printf("%d ",a[i]);
	    }
	    break;
   case 3 : printf(" Enter the limit : ");
	    scanf("%d",&n);
	    printf(" Enter the numbers : ");
	    for(i=1;i<=n;i++)
	    {
	     scanf("%d",&a[i]);
	    }
	    for(i=1;i<=n-1;i++)
	    {
	     for(j=1;j<=n-i;j++)
	     {
	      if(a[j]>a[j+1])
	      {
	       temp=a[j];
	       a[j]=a[j+1];
	       a[j+1]=temp;
	      }
	     }
	    }
	    printf(" Array after sorting : ");
	    for(i=1;i<=n;i++)
	    {
	     printf("%d ",a[i]);
	    }
	    break;
   case 4 : exit(0);
   default : printf(" Error in choice");
  }
 }
}











































































































































































































































































































