#include<iostream>
#include<algorithm>
using namespace std;

//declare a class with name job
class Job
{
public:
  //declare data members
  string jobID;
  int profit,deadline;

  void getProperty(string j,int p,int d)
  {
    jobID = j;
    profit = p;
    deadline = d;
  }
};

bool comparable(Job j1,Job j2)
{
  return (j1.profit>j2.profit);
}

int main()
{
  Job j1,j2,j3,j4,j5;
  int pos,tp=0;
  j1.getProperty("j1",10,3);
  j2.getProperty("j2",20,3);
  j3.getProperty("j3",30,3);
  j4.getProperty("j4",5,4);
  j5.getProperty("j5",80,4);

  //declare array of class(job)
  Job j[] = {j1,j2,j3,j4,j5};
  int n = sizeof(j)/sizeof(j[0]);

  //arrange all jobs in decreasing order of profit
  sort(j,j+n,comparable);
  pos = j[0].deadline;

  //find maximum deadline
  for(int i=1;i<n;i++)
  {
    if(j[i].deadline>j[i-1].deadline)
    {
      pos = j[i].deadline;
    }
  }
  //array size is equal to maximum deadline
  int a[pos];
  bool position[pos];
  //initially declare each position as false
  for(int i=0;i<n;i++)
  {
    position[i] = false;
  }

  //find a job
  for(int i=0;i<n;i++)
  {
    for(int k=min(n,j[i].deadline)-1;k>=0;k--)
    {
      if(position[k]==false)
      {
        a[k] = i;
        position[k] = true;

        //calculate total profit
        tp = tp + j[a[k]].profit;
        break;
      }
    }
  }
  cout<<"Total Profit is: "<<tp<<endl;

  //print how many jobs selected
  for(int i=0;i<n;i++)
  {
    if(position[i]==true)
    {
      cout<<j[a[i]].jobID<<" ";
    }
  }
}
