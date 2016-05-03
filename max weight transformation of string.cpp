#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

int getMaxRec(string &str, int i, int n, int lookup[])
{
    // Base case
    if (i >= n) return 0;
 
    //If this subproblem is already solved
    if (lookup[i] != -1) return lookup[i];
 
    // Don't make pair, so weight gained is 1
    int ans = 1 + getMaxRec(str, i+1, n, lookup);
 
    // If we can make pair
    if (i+1 < n)
    {
      // If elements are dissmilar, weight gained is 4
      if (str[i] != str[i+1])
        ans = max(4 + getMaxRec(str, i+2, n, lookup),
                  ans);
 
      // if elements are similar so for making a pair
      // we toggle any of them. Since toggle cost is
      // 1 so overall weight gain becomes 3
      else ans = max(3 + getMaxRec(str, i+2, n, lookup),
                    ans);
    }
 
    // save and return maximum of above cases
    return lookup[i] = ans;
}
 
// Initializes lookup table and calls getMaxRec()
int getMaxWeight(string str)
{
    int n = str.length();
 
    // Create and initialize lookup table
    int lookup[n];
    memset(lookup, -1, sizeof lookup);
 
    // Call recursive function
    int len = getMaxRec(str, 0, str.length(), lookup);
    cout<<endl;
    for(int i = 0; i < n; i++)
      cout<<lookup[i]<<" ";
    return len;
}

int max_wt(string str)
{
  int len = str.length();
  int wt[len];
  wt[0] = 1;
  //wt[1] = str[0] == str[1] ? 1 : 4;
  
  for(int i = 1; i < len; i++)
  {
    if(str[i-1] == str[i]) // toggling
    {
      if(i >= 2 && wt[i-1] + 1 < wt[i-2] + 3)
      {
        str[i] = str[i] == 'B' ? 'A' : 'B';
        wt[i] = wt[i-2] + 3;
      }
      else if(i < 2)
      {
        str[i] = str[i] == 'B' ? 'A' : 'B';
        wt[i] = 3;
      }
      else
        wt[i] = wt[i-1] + 1;
    }
    else
    {
      if(i%2 != 0 && i > 2)
      {
        wt[i] = wt[i-2] + 4;
      }
      else if(i == 1)
        wt[i] = 4;
      else 
        wt[i] = wt[i-1] + 1;
    }
  }
  cout<<str<<endl;
  for(int i = 0; i < len; i++)
    cout<<wt[i]<<" ";
  cout<<endl;
  return wt[len-1];
}

int main()
{
  string str;
  cin>>str;
  cout<<str<<endl;
  cout<<max_wt(str)<<endl;
  cout<<getMaxWeight(str)<<endl;
  return 0;
}
