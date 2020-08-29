#include<iostream>
using namespace std;

int BinarySearch(int a[],int i,int j,int key)
{
  int i1=i;
  int j1=j;
  int mid,found=0;
  do{
    mid=(i1+j1)/2;
    if(key<a[mid]){
      j1=mid-1;
    }
    else if(key>a[mid]){
      i1=mid+1;
    }
    else if(a[mid]==key)
    {
      cout<<"element is found and index is: "<<mid;
      return 1;
    }
  }while(i1<=j1);
  if(found==0){
    cout<<"element is not found"<<endl;
  }
}
int main()
{
  int key;
  int a[5]={1,2,3,4,5};
  cout<<"enter a number you want to search: ";
  cin>>key;
  BinarySearch(a,0,4,key);
}
