//program to perform multiplication of two matrices
//using operator overloading
#include<iostream>

#include<iomanip>
class matrix
{
 private : int mat[10][10];
	   int rc;
 public : matrix()
	  {
	  }
	  void size(int n)
	  {
	   rc=n;
	  }
	  void matinput();
	  void matprint();
	  matrix operator *(matrix);
};
void matrix::matinput()
{
 cout<<" Type "<<rc*rc<<" element : ";
 for(int i=0;i<rc;i++)
 {
  for(int j=0;j<rc;j++)
  {
   cin>>mat[i][j];
  }
 }
}
void matrix::matprint()
{
 for(int i=0;i<rc;i++)
 {
  for(int j=0;j<rc;j++)
  {
   cout<<setw(3)<<mat[i][j];
  }
  cout<<"\n";
 }
}
matrix matrix::operator *(matrix m)
{
 matrix matprod;
 matprod.size(rc);
 for(int i=0;i<rc;i++)
 for(int j=0;j<rc;j++)
 {
  matprod.mat[i][j]=0;
  for(int k=0;k<rc;k++)
  matprod.mat[i][j]=matprod.mat[i][j]+mat[i][k]*m.mat[k][j];
 }
 return matprod;
}
int main()
{
 matrix a,b,c;
 int rc;
 clrscr();
 cout<<"\nType the order of the matrix : ";
 cin>>rc;
 a.size(rc);
 b.size(rc);
 c.size(rc);
 cout<<"\nMatrix A\n";
 a.matinput();
 cout<<"\nMatrix B\n";
 b.matinput();
 cout<<"\nMatrix A\n";
 a.matprint();
 cout<<"\nMatrix B\n";
 b.matprint();
 c=a*b;
 cout<<"\nProduct of matrix\n";
 c.matprint();
 return 0;
}