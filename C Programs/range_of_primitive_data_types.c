// program to print range of primitive data types

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
	printf("\n-----------------------------------------------------------------------------\n");

	printf("\n                      RANGE OF PRIMITIVE DATA TYPES                          \n");

	printf("\n                     -------------------------------                           ");

	printf("\n\n Range of char is :  %d  to  %d",CHAR_MIN,CHAR_MAX);

	printf("\n\n Range of unsigned char is :  0  to  %u",UCHAR_MAX);


	printf("\n\n\n Range of int is :  %d  to  %d",INT_MIN,INT_MAX);

	printf("\n\n Range of unsigned int is :  0  to  %u",UINT_MAX);


	printf("\n\n\n Range of short int is :  %d  to  %d",SHRT_MIN,SHRT_MAX);

	printf("\n\n Range of unsigned short int is :  0  to  %u",USHRT_MAX);


	printf("\n\n\n Range of long int is :  %ld  to  %ld",LONG_MIN,LONG_MAX);

	printf("\n\n Range of unsigned long int is :  0  to  %lu",ULONG_MAX);


	printf("\n\n\n Range of long long int is :  %lld  to  %lld",LLONG_MIN,LLONG_MAX);

	printf("\n\n Range of unsigned long long int is :  0  to  %llu",ULLONG_MAX);


	printf("\n\n\n Range of Normalised float is :  %.138f  to  %.138f",-FLT_MIN,FLT_MIN);

	printf("\n\n Range of Denormalised float is :  %.0f  to  %.0f",-FLT_MAX,FLT_MAX);

	printf("\n\n Range of Normalised double is :  %.0lf  to  %.0lf",-DBL_MIN,DBL_MIN);

	printf("\n\n Range of Denormalised double is :  %.0lf  to  %.0lf",-DBL_MAX,DBL_MAX);

	printf("\n\n Range of Normalised long double is :  %.0Lf  to  %.0Lf",-LDBL_MIN,LDBL_MIN);

	printf("\n\n Range of Denornmalised long double is :  %.0Lf  to  %.0Lf",-LDBL_MAX,LDBL_MAX);

	printf("\n\n-----------------------------------------------------------------------------\n\n");

	return 0;
}
