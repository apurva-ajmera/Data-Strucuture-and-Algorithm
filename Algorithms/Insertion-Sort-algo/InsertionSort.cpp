#include<iostream>
using namespace std;

void InsertionSort(int a[],int n)
{
  int temp,j;
  for(int i=1;i<n;i++)
  {
    j=i-1;
    int key = a[i];
    while(j>=0 && a[j]>key)
    {
      a[j+1] = a[j];
      j = j-1;
    }
    a[j+1] = key;
  }
  cout<<"sorted array is: ";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}

int main()
{
  int n,num;
  cout<<"enter how many numbers you want to insert: ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cout<<"enter a number: ";
    cin>>num;
    a[i] = num;
  }
  InsertionSort(a,n);
}
