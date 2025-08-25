// program to print size of primitive data types

#include<stdio.h>

int main()
{
	printf("\n-----------------------------------------------------------------------------\n");

	printf("\n                      SIZE OF PRIMITIVE DATA TYPES                           \n");

	printf("\n                     ------------------------------                            ");

	printf("\n\n Size of char is : %zu byte",sizeof(char));

	printf("\n\n Size of unsigned char is : %zu byte",sizeof(unsigned char));


	printf("\n\n\n Size of int is : %zu bytes",sizeof(int));

	printf("\n\n Size of unsigned int is : %zu bytes",sizeof(unsigned int));


	printf("\n\n\n Size of short int is : %zu bytes",sizeof(short int));

	printf("\n\n Size of unsigned short int is : %zu bytes",sizeof(unsigned short int));


	printf("\n\n\n Size of long int is : %zu bytes",sizeof(long int));

	printf("\n\n Size of unsigned long int is : %zu bytes",sizeof(unsigned long int));


	printf("\n\n\n Size of long long int is : %zu bytes",sizeof(long long int));

	printf("\n\n Size of unsigned long long int is : %zu bytes",sizeof(unsigned long long int));


	printf("\n\n\n Size of float is : %zu bytes",sizeof(float));

	printf("\n\n Size of double is : %zu bytes",sizeof(double));

	printf("\n\n Size of long double is : %zu bytes",sizeof(long double));

	printf("\n\n-----------------------------------------------------------------------------\n\n");

	return 0;
}
