#include<iostream>
using namespace std;

void SelectionSort(int a[],int n){
  int temp,pos,small;
  for(int i=1;i<n;i++)
  {
    pos = i-1;
    for(int j=i;j<n;j++)
    {
      small = a[pos];
      if(a[j]<small)
      {
        small = a[j];
        pos = j;
      }
    }
    if(pos!=(i-1))
    {
      temp = a[i-1];
      a[i-1] = small;
      a[pos] = temp;
    }
    cout<<"pass "<<i<<":"<<endl;
    for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  cout<<"sorted array is: ";
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
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
  SelectionSort(a,n);
}
