#include<stdio.h>
#include<string.h>

int StringPatternMatching(char text[100], char pattern[100])
{
	int i, j, index;

	int n = strlen(text);
	int m = strlen(pattern);

	for(i = 0; i < n - m; i++)
	{
		index = i;

		for(j = 0; j < m; j++)
		{
			if(text[i + j] != pattern[j])
			{
				break;
			}
		}

		if(j == m)
		{
			return index;
		}
	}

	return -1;
}

int main()
{
	char text[100], pattern[100];
	int index;

	printf("\n Enter the text string : ");
	scanf("%s", text);

	printf("\n Enter the pattern to be matched : ");
	scanf("%s", pattern);

	index = StringPatternMatching(text, pattern);

	if(index == -1)
	{
		printf("\n The pattern does not exist in text string \n\n");
	}
	else
	{
		printf("\n The pattern in text string is found at index : %d \n\n", index);
	}

	return 0;
}
