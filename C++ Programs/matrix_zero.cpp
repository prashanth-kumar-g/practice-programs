#include<iostream>
#include<vector>

using namespace std;

void changeMatrixZero(vector<vector<int>> &vect)
{
    int r = vect.size(), c = vect[0].size();

    int i_f, j_f;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(vect[i][j] == 0)
            {
                i_f = i;
                j_f = j;
                break;
            }
        }
    }
    
    for(int j = 0; j < c; j++)
    {
        vect[i_f][j] = 0;
    }

    for(int i = 0; i < r; i++)
    {
        vect[i][j_f] = 0;
    }
}

int main()
{
    int r, c;
    printf("\n Enter the dimensions of matrix(rows & columns) : ");
    scanf("%d %d", &r, &c);

    vector<vector<int>> vect(r, vector<int>(c));
    printf("\n Enter the matrix elements : \n ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin>>vect[i][j];
        }
    }

    changeMatrixZero(vect);

    printf("\n The changed matrix is : \n ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout<<" "<<vect[i][j]<<" ";
        }
        cout<<endl<<" ";
    }

    cout<<endl;

    return 0;
}