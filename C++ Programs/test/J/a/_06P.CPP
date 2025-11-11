#include<iostream>

using namespace std;

int main()
{
    int r, c;
    cout<<"\n Enter the row and column size : ";
    cin>>r>>c;

    int mat[r][c];
    cout<<"\n Enter the matrix elements : \n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin>>mat[i][j];
        }   
    }

    int invMat[c][r];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            invMat[j][i] = mat[i][j];
        }   
    }

    cout<<"\n The transpose of matrix is : \n";
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            cout<<invMat[i][j]<<"  ";
        }
        cout<<endl;  
    }

    cout<<"\n";

    return 0;
}