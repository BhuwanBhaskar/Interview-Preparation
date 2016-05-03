#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_min_coins(vector<int> vcoins)
{
  int sum = 0;
  int nmc = 0;
  int mval = 0;
  
  for(int i = 0; i < vcoins.size(); i++)
    sum += vcoins[i];
  
  for(int j = vcoins.size()-1; j >= 0; j--)
  {
    if(sum  >= mval)
    {
      sum -= vcoins[j];
      mval += vcoins[j];
      nmc++;
    }
  }
  return nmc;
}

int main()
{
  int n = 0;
  cin>>n;
  
  vector<int> vcoins;
  for(int i = 0; i < n; i++)
  {
    int temp;
    cin>>temp;
    vcoins.push_back(temp);
  }

  sort(vcoins.begin(),vcoins.end());
  
  cout<<find_min_coins(vcoins);
  
  return 0;
}
