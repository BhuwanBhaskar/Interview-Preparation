#include<iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  
  string stones;
  cin>>stones;
  int p = 0;
  int cnt = 0;
  while(p < stones.length())
  {
    if(stones[p] == 'R')
    {
      int i = p+1;
      while(stones[i] == 'R')
      {
        i++;
        cnt++;
      }
      p = i;
    }
    if(stones[p] == 'G')
    {
      int i = p+1;
      while(stones[i] == 'G')
      {
        i++;
        cnt++;
      }
      p = i;
    }
    if(stones[p] == 'B')
    {
      int i = p+1;
      while(stones[i] == 'B')
      {
        i++;
        cnt++;
      }
      p = i;
    }
  }
  cout<<cnt;
  return 0;
}
