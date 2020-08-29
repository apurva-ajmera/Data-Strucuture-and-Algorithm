#include<iostream>
#include<algorithm>
using namespace std;

class Greedy{
public:
  //p for profit and w for weight
  float p,w;

  //ratio of profit by weight
  float pbyw;

  void getGreedy(float profit,float weight)
  {
    p=profit;
    w=weight;
    pbyw=profit/weight;
  }
};

//sorting according to ratio of profit by weight
bool comparable(Greedy g1,Greedy g2)
{
  return (g1.pbyw>g2.pbyw);
}

int main()
{
  Greedy g1,g2,g3,g4,g5,g6,g7;
  //c for capacity,tc for total capacity,tp for total profit
  float c,tc=0,tp=0,temp=1,unit=1;
  g1.getGreedy(10,2);
  g2.getGreedy(5,3);
  g3.getGreedy(15,5);
  g4.getGreedy(7,7);
  g5.getGreedy(6,1);
  g6.getGreedy(18,4);
  g7.getGreedy(3,1);
  Greedy g[] = {g1,g2,g3,g4,g5,g6,g7};
  int n = sizeof(g)/sizeof(g[0]);
  sort(g,g+n,comparable);
  cout<<"what is maximum weight: ";
  cin>>c;
  for(int i=0;i<n;i++)
  {
    if(g[i].w<=c && tc<c)
    {
      temp = temp + g[i].w;
      if(temp>c)
      {
        unit = (c-tc)/g[i].w;
        tc = tc + (c-tc);
        tp = tp + unit*(g[i].p);
      }
      else{
       tc = tc + g[i].w;
       tp = tp + unit*(g[i].p);
    }
    }
  }
  cout<<"Total profit is: "<<tp;
}
