#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r)
{
  int n1,n2;
  n1 = q-p+1;
  n2 = r-q;
  int left_array[n1];
  int right_array[n2];

  //assign value to the left_array
  for(int i=0;i<n1;i++)
  {
    left_array[i] = a[p+i];
  }

  //assing value to right_array
  for(int i=0;i<n2;i++)
  {
    right_array[i] = a[q+1+i];
  }

  int left_array_index = 0,right_array_index = 0,k=p;

  while(left_array_index<n1 && right_array_index<n2)
  {
    if(left_array[left_array_index] <= right_array[right_array_index])
    {
      a[k] = left_array[left_array_index];
      left_array_index++;
    }
    else
    {
      a[k] = right_array[right_array_index];
      right_array_index++;
    }
    k++;
  }

  while(left_array_index<n1)
  {
    a[k] = left_array[left_array_index];
    left_array_index++;
    k++;
  }

  while(right_array_index<n2)
  {
    a[k] = right_array[right_array_index];
    right_array_index++;
    k++;
  }
}

void mergeSort(int a[],int p,int r)
{
  int q;
  if(p<r)
  {
    q = (p+r)/2;
    mergeSort(a,p,q);
    mergeSort(a,q+1,r);
    merge(a,p,q,r);
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
  mergeSort(a,0,n-1);
  cout<<"sorted array is: ";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}
