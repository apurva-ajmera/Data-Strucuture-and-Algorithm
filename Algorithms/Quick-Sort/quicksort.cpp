#include<iostream>
using namespace std;

int partition(int a[],int p,int r)
{
  int pivot,i,j,temp;
  i=p-1;
  pivot = a[r];
  for(j=p;j<=r-1;j++)
  {
    if(a[j]<=pivot)
    {
      i+=1;
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  temp = a[i+1];
  a[i+1] = a[r];
  a[r] = temp;
  return(i+1);
}

void quickSort(int a[],int p,int r)
{
  int q;
  if(p<r)
  {
    q = partition(a,p,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
  }
}

int main()
{
  int n,num;
  cout<<"how many numbers you want to insert: ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cout<<"enter a number: ";
    cin>>num;
    a[i] = num;
  }
  quickSort(a,0,n-1);
  cout<<"sorted array is: ";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}
