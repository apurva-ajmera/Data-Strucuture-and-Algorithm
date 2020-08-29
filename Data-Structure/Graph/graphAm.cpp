#include<iostream>
using namespace std;

int main()
{
  int a[3][3];
  string choice;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<"is there edge between "<<i<<" and "<<j<<" yes or no :";
      cin>>choice;
      if(choice=="yes")
      {
        a[i][j] = 1;
      }
      else
      {
        a[i][j] = 0;
      }
    }
  }
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(a[i][j]==1)
      {
        cout<<"edge between "<<i<<" and "<<j<<endl;
      }
      else
      {
        cout<<"no edge between "<<i<<" and "<<j<<endl;
      }
    }
  }
}
