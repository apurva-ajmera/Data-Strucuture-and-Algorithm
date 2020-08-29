#include<iostream>
using namespace std;

void BubbleSort(int a[],int n)
{
  int temp;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  cout<<"sorted array is: ";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}

int main(){
  int n,num;
  cout<<"enter a number of elements you want to insert: ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>num;
    a[i] = num;
  }
  BubbleSort(a,n);
}
