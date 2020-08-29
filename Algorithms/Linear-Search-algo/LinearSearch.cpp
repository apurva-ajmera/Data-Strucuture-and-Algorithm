#include<iostream>
using namespace std;

//implementation of linear search algorithm
void LinearSearch(int a[],int n,int key)
{
  int index,found=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==key)
    {
      found = 1;
      index = i;
    }
  }
  if(found == 1)
  {
    cout<<"element is found and index is: "<<index;
  }
  else
  {
    cout<<"element not found";
  }
}

int main()
{
  int n,key,num;
  cout<<"enter number of elements you want to insert: ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>num;
    a[i]=num;
  }
  cout<<"which element you want to search: ";
  cin>>key;
  LinearSearch(a,n,key);
}
