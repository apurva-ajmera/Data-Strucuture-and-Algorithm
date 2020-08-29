#include<iostream>
#include<algorithm>
using namespace std;

//implementation to solve makechange
void makeChange(int coins[],int v,int n)
{
  int a[n+1][v+1],temp;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=v;j++)
    {
      if(i==0 || j==0)
      {
        a[i][j] = 0;
      }
      //if given value is greater than coin's value
      else if(j-coins[i-1]>=0)
      {
        a[i][j] = a[i][j-coins[i-1]]+1;
      }
      //if given value is not greater than coin's value
      else
      {
        a[i][j] = a[i-1][j];
      }
    }
  }
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=v;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"minimum coin require to fulfill value of "<<v<<" is: "<<a[n][v];
}

int main()
{
  //array of coins
  int coins[] = {1,2,5};
  int value = 11;
  int n = sizeof(coins)/sizeof(coins[0]);
  makeChange(coins,value,n);
}
