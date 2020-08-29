#include<iostream>
using namespace std;

void swap(int *i,int *j)
{
  int *temp;
  *temp = *i;
  *i =  *j;
  *j = *temp;
}

void heapify(int a[],int n,int i)
{
  int largest,l,r;
  largest = i;
  l = 2*i + 1;
  r = 2*i + 2;

  if(l<n  && a[l]>a[largest])
      largest = l;
  if(r<n && a[r]>a[largest])
      largest = r;
  if(largest!=i)
  {
    swap(a[i],a[largest]);
    heapify(a,n,largest);
  }
}

void heap_sort(int a[],int n)
{
  //first convert array into max-heap
  for(int i=n/2-1;i>=0;i--)
  {
    heapify(a,n,i);
  }
  //apply heap-sort
  for(int i =n-1;i>=0;i--){
    swap(a[0],a[i]);
    heapify(a,i,0);
  }

  //print sorted array
  cout<<"sorted array is: ";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}

int main()
{
  int n;
  int a[] = {13,24,15,65,2};
  n = sizeof(a)/sizeof(a[0]);
  heap_sort(a,n);
}
