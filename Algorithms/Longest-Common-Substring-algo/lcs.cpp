#include<iostream>
#include<algorithm>
using namespace std;

//implementation of longest common sequence
void lcs(string s1,string s2,int n1,int n2)
{
  int a[n2+1][n1+1];
  for(int i=0;i<=n2;i++)
  {
    for(int j=0;j<=n1;j++)
    {
      if(i==0 || j==0)
      {
        a[i][j] = 0;
      }
      else if(s2[i-1]==s1[j-1])
      {
        a[i][j] = a[i-1][j-1]+1;
      }
      else
      {
        a[i][j] = max(a[i-1][j],a[i][j-1]);
      }
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"length of longest common subsequence is: "<<a[n2][n1]<<endl;
  int l = a[n2][n1];

  //for storing common substring
  char c[l];
  int j=n2,i=n1;

  //find common substring
  while(i!=0 && j!=0){
    if(a[j][i] != max(a[j-1][i],a[j][i-1]))
    {
      l--;
      c[l] = s1[i-1];
      i=i-1;
      j=j-1;
    }
    else if(a[j][i] == a[j-1][i])
    {
      j = j-1;
    }
    else
    {
      i = i-1;
    }
  }
  cout<<endl;
  cout<<"longest common subsequence is: ";
  for(int k=0;k<a[n2][n1];k++)
  {
    cout<<c[k]<<" ";
  }
}

int main()
{
  //first string
  string str1 = "AGGTAB";
  //second string
  string str2 = "GXTXAYB";
  int n1 = str1.size();
  int n2 = str2.size();
  lcs(str1,str2,n1,n2);
}
