// self referential structure and array of structure
#include<iostream>

int main()
{
 struct node
 {
  int n;
  char ch;
  struct node *l;
 };
 clrscr();
 struct node var[4];

 cout<<"\nEnter four numbers and characters\n\n";
 for(int i=1;i<=4;i++)
 {
  cout<<" "<<i<<")  ";
  cin>>var[i].n>>var[i].ch;
 }

 var[1].l=&var[2];
 var[2].l=&var[3];
 var[3].l=&var[4];
 var[4].l=&var[1];

 cout<<"\n\nThe elements are\n\n";
 for(i=1;i<=4;i++)
 {
  cout<<" var["<<i<<"].n = "<<var[i].n<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=4;i++)
 {
  cout<<" var["<<i<<"].ch = "<<var[i].ch<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=4;i++)
 {
  cout<<" var["<<i<<"].l = "<<var[i].l<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=4;i++)
 {
  cout<<" var["<<i<<"].l->n = "<<var[i].l->n<<"   ";
 }

 cout<<"\n\n";
 for(i=1;i<=4;i++)
 {
  cout<<" var["<<i<<"].l->ch = "<<var[i].l->ch<<"   ";
 }

 return 0;
}
