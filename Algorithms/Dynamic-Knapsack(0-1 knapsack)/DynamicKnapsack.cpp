#include<iostream>
#include<algorithm>
using namespace std;

//finding maximum value sing dynamic programming
void findValue(int weights[],int values[],int n,int capacity)
{
  int a[n+1][capacity+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=capacity;j++)
    {
      if(i==0 || j==0)
      {
        a[i][j] = 0;
      }
      else if(j>=weights[i-1])
      {
        a[i][j] = max(values[i-1]+a[i-1][j-weights[i-1]],a[i-1][j]);
      }
      else
      {
        a[i][j] = a[i-1][j];
      }
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"maximum value is: "<<a[n][capacity]<<"$";
}

int main()
{
  int weights[] = {1,3,4,5};
  int values[] = {1,4,5,7};
  int n = sizeof(weights)/sizeof(weights[0]);
  int capacity = 7;
  findValue(weights,values,n,capacity);
}
