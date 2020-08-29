#include<iostream>
#include<algorithm>
using namespace std;

class Activity
{
public:
  //declare start time and end time of activity
  int start,finish;
  //name of the activity
  string name;

  void getProperty(string n,int i,int j)
  {
    start = i;
    finish = j;
    name = n;
  }
};

//sort activity according to it's finish time
bool comparable(Activity a,Activity b)
{
  return (a.finish<b.finish);
}

int main()
{
  Activity a1,a2,a3,a4,a5,a6;
  int cnt = 0;
  a1.getProperty("A1",0,6);
  a2.getProperty("A2",3,4);
  a3.getProperty("A3",1,2);
  a4.getProperty("A4",5,9);
  a5.getProperty("A5",5,7);
  a6.getProperty("A6",8,9);
  Activity a[] = {a1,a2,a3,a4,a5,a6};

  //find number of activity
  int n = sizeof(a)/sizeof(a[0]);

  //sort array of an object
  sort(a,a+n,comparable);
  cout<<"Order of activity is: "<<endl;

  //first activity always selected
  cout<<"Activity "<<"StartTime "<<"FinishTime"<<endl;
  cout<<a[0].name<<"\t "<<a[0].start<<"\t\t"<<a[0].finish;
  cout<<endl;
  int j=0;

  //selecting activity
  for(int i=1;i<n;i++)
  {
    if(a[i].start>=a[j].finish)
    {
      cout<<a[i].name<<"\t "<<a[i].start<<"\t\t"<<a[i].finish;
      cout<<endl;
      j=i;
    }
  }
}
