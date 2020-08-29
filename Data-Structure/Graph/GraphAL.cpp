#include<iostream>
#include<vector>
using namespace std;

int main()
{
  //declare vector
  vector<int> v[3];
  v[0].push_back(1);
  v[0].push_back(0);
  v[1].push_back(2);
  v[1].push_back(0);
  v[2].push_back(0);
  v[2].push_back(1);
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
      cout<<"edge present between node "<<i<<" and node "<<v[i][j]<<endl;
    }
  }
}
