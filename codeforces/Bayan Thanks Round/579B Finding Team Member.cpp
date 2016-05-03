#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct team
{
  int strength,p1,p2;
};

int myComp(struct team t1, struct team t2)
{
  return t1.strength > t2.strength;
}

int main()
{
  int t;
  cin>>t;
  
  vector<struct team> teams;
  
  int cnt = 1,pcnt,x = 0;
  for(int i = 1; i <= 2*t-1; i++)
  {
    pcnt = cnt;
    for(int j = cnt,k = 1; j <= pcnt+i-1; j++,cnt++,k++)
    {
      struct team t1;
      cin>>t1.strength;
      t1.p1 = i+1;
      t1.p2 = k;
      teams.push_back(t1);
    }
  }
  
  sort(teams.begin(),teams.end(),myComp);
  int arr[2*t+1];
  
  for(int it = 0; it < teams.size(); it++)
  {
    if(teams[it].strength != 0)
    {
      arr[teams[it].p1] = teams[it].p2;
      arr[teams[it].p2] = teams[it].p1;
    }
    else
      continue;
  
    for(int itr = it ; itr < teams.size(); itr++)
    {
      int x = teams[it].p1,y = teams[it].p2;
      
      if(teams[itr].p1 == x || teams[itr].p2 == x || teams[itr].p1 == y || teams[itr].p2 == y)
      {
        teams[itr].strength = 0;
      }
    }
  }
  
  for(int i = 1; i <= 2*t; i++)
    cout<<arr[i]<<" ";
  return 0;
}
