#include<stdio.h>

int main()
{
    int r, c;
    printf("\n Enter the dimensions of matrix(rows & columns) : ");
    scanf("%d %d", &r, &c);

    int arr[r][c];
    printf("\n Enter the matrix elements : \n ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int i_f, j_f;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(arr[i][j] == 0)
            {
                i_f = i;
                j_f = j;
                break;
            }
        }
    }
    
    for(int j = 0; j < c; j++)
    {
        arr[i_f][j] = 0;
    }

    for(int i = 0; i < r; i++)
    {
        arr[i][j_f] = 0;
    }
        

    printf("\n The changed matrix is : \n ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n ");
    }

    return 0;
}