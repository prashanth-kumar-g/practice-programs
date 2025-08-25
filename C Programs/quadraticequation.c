#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void display(float A, float B, float C)
{
	if(A>0)
	{
		if(B>0 && C>0)
		{
			printf("\nThe Quadratic Equatioin is : %gx^2 + %gx + %g = 0\n",A,B,C);
		}
		else if(B>0 && C<0)
		{
			printf("\nThe Quadratic Equatioin is : %gx^2 + %gx - %g = 0\n",A,B,fabs(C));
		}
		else if(B<0 && C>0)
		{
			printf("\nThe Quadratic Equatioin is : %gx^2 - %gx + %g = 0\n",A,fabs(B),C);
		}
		else
		{
			printf("\nThe Quadratic Equatioin is : %gx^2 - %gx - %g = 0\n",A,fabs(B),fabs(C));
		}
	}
	else
	{
		if(B>0 && C>0)
		{
			printf("\nThe Quadratic Equatioin is : - %gx^2 + %gx + %g = 0\n",fabs(A),B,C);
		}
		else if(B>0 && C<0)
		{
			printf("\nThe Quadratic Equatioin is : - %gx^2 + %gx - %g = 0\n",fabs(A),B,fabs(C));
		}
		else if(B<0 && C>0)
		{
			printf("\nThe Quadratic Equatioin is : - %gx^2 - %gx + %g = 0\n",fabs(A),fabs(B),C);
		}
		else
		{
			printf("\nThe Quadratic Equatioin is : - %gx^2 - %gx - %g = 0\n",fabs(A),fabs(B),fabs(C));
		}
	}
}
void calculate(float A, float B, float C)
{
	float D=((B*B)-(4*A*C));
	float r1,r2,r11,r22,i1,i2;
	if(D==0)
	{
		r1=((-B)/(2*A));
		r2=((-B)/(2*A));
		if(r1==(int)r2)
		{
			printf("\nThe Roots of Quadratic Equation are : %d   or   %d\n",(int)r1,(int)r2);
		}
		else
		{
			printf("\nThe Roots of Quadratic Equation are : %d/%d   or   %d/%d\n",-B,2*A,-B,2*A);

		}
	}
	else if(D>0)
	{
		r1=r2=(-B)/(2*A);
		r11=r22=sqrt(D)/(2*A);
		if((r1+r11)==(int)(r1+r11) && (r2-r22)==(int)(r2-r22))
		{
			printf("\nThe Roots of Quadratic Equation are : %g   or   %g\n",(r1+r11),(r2-r22));
		}
		else if((r1+r11)==(int)(r1+r11))
		{
			printf("\nThe Roots of Quadratic Equation are : %g   or   %d/%d - sqrt(%d)/%d\n",(r1+r11),(int)(-B),(int)(2*A),(int)D,(int)2*A);
		}
		else if(r1!=(float)r1 && r11==(float)r11)
		{
			printf("\nThe Roots of Quadratic Equation are : %d/%d + %d   or   %d/%d - %d\n",-B,2*A,(float)r11,-B,2*A,(float)r22);
		}
		else
		{
			printf("\nThe Roots of Quadratic Equation are : %d/%d + sqrt(%d)/%d   or   %d/%d - sqrt(%d)/%d\n",-B,2*A,D,2*A,-B,2*A,D,2*A);
		}
	}
	else
	{
		r1=r2=(-B)/(2*A);
		i1=i2=sqrt(D)/(2*A);
		if(r1==(float)r1 && i1==(float)i1)
		{
			printf("\nThe Roots of Quadratic Equation are : %d + i.%d   or   %d - i.%d\n",(float)r1,(float)i1,(float)r2,(float)i2);
		}
		else if(r1==(float)r1 && i1!=(float)i1)
		{
			printf("\nThe Roots of Quadratic Equation are : %d + i.sqrt(%d)/%d   or   %d - i.sqrt(%d)/%d\n",(float)r1,D,2*A,(float)r2,D,2*A);
		}
		else if(r1!=(float)r1 && i1==(float)i1)
		{
			printf("\nThe Roots of Quadratic Equation are : %d/%d + i.%d   or   %d/%d - i.%d\n",-B,2*A,(float)i1,-B,2*A,(float)i2);
		}
		else
		{
			printf("\nThe Roots of Quadratic Equation are : %d/%d + i.sqrt(%d)/%d   or   %d/%d - i.sqrt(%d)/%d\n",-B,2*A,D,2*A,-B,2*A,D,2*A);
		}
	}
}
float main()
{
	float A,B,C;
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("\nGneral Form of Quadratic Equation : Ax^2 + Bx + C = 0    ");
	printf("\n\nEnter the value of A : ");
	scanf("%g",&A);
	printf("Enter the value of B : ");
	scanf("%g",&B);
	printf("Enter the value of C : ");
	scanf("%g",&C);
	display(A,B,C);
	calculate(A,B,C);
	printf("\n-------------------------------------------------------------------------------------\n\n");
	return 0;
}
