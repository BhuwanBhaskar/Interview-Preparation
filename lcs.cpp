#include<iostream>

using namespace std;

int lcs(string str1, string str2)
{
  int l1 = str1.length();
  int l2 = str2.length();
  
  int sol[l1+1][l2+1];
  
  for(int i = 0; i <= l1; i++)
  {
    for(int j = 0; j <= l2; j++)
    {
      if(i == 0 || j == 0 )
        sol[i][j] = 0;
      else
        sol[i][j] = str1[i-1] == str2[j-1] ? sol[i-1][j-1]+1 : max(sol[i-1][j],sol[i][j-1]);   
    }
  }
  
  int i = l1,j = l2, k = sol[l1][l2];
  char sub[k+1];
  sub[k] = '\0';
  
  while(i > 0 && j > 0)
  {
    if(sol[i][j-1] == sol[i-1][j] && sol[i][j-1] != sol[i][j])
    {
      sub[k-1] = str1[i];
      i = i-1;
      j = j-1;
      k--;
    }
    else if(sol[i][j-1] == sol[i-1][j])
    {
      i--;
      j--;
    }
    else if(sol[i][j-1] > sol[i-1][j])
      j = j-1;
    else if(sol[i][j-1] < sol[i-1][j])
      i = i-1;
  }
  cout<<sub<<endl;
  return sol[l1][l2];
}

int lrs(string str1, string str2)
{
  int l1 = str1.length();
  int l2 = str2.length();
  
  int sol[l1+1][l2+1];
  
  for(int i = 0; i <= l1; i++)
  {
    for(int j = 0; j <= l2; j++)
    {
      if(i == 0 || j == 0 )
        sol[i][j] = 0;
      else if(i != j)
        sol[i][j] = str1[i-1] == str2[j-1] ? sol[i-1][j-1]+1 : max(sol[i-1][j],sol[i][j-1]);
      else
        sol[i][j] = max(sol[i-1][j],sol[i][j-1]);
    }
  }
  
  int i = l1,j = l2, k = sol[l1][l2];
  char sub[k+1] = "";
  sub[k] = '\0';
  cout<<k-1<<endl;
  while(i > 0 && j > 0)
  {
    if(sol[i][j-1] == sol[i-1][j])
    {
      sub[k-1] = str1[i];
      cout<<k-1<<" "<<str1[i]<<endl;
      i = i-1;
      j = j-1;
      k--;
    }
    else if(sol[i][j-1] > sol[i-1][j])
      j = j-1;
    else if(sol[i][j-1] < sol[i-1][j])
      i = i-1;
  }
  cout<<sub<<endl;
  return sol[l1][l2];
}

int main()
{
  string str1,str2;
  cin>>str1>>str2;
  
  //cout<<lcs(str1,str2)<<endl;
  cout<<lrs(str1,str1)<<endl;
  return 0;
}
