#include<iostream>

using namespace std;

void swap(char *a, char *b)
{
  char t = *a;
  *a = *b;
  *b = t;
}

int main()
{
  string sum;
  cin>>sum;
  
  int b = 0, e = sum.length()-1;
  int pb = b, pe = e;
  
  while(true)
  {
    while(sum[pb] == '1')
      pb+=2;
    b = pb; 
    while(b < sum.length() && sum[pb] <= sum[b])
      b+=2;
    if(b < sum.length() && sum[pb] > sum[b])
    {
      swap(sum[pb],sum[b]);
      if(sum[pb] == '1')
        pb+=2;
    }
    while(sum[pe] == '3')
      pe-=2;
    e = pe;  
    while(e >= 0 && sum[pe] >= sum[e])
      e-=2;
    if(e >= 0 && sum[pe] < sum[e])
    {
      swap(sum[pe],sum[e]);
      if(sum[pe] == '3')
        pe-=2;
    }
    
    if(b >= sum.length() && e <= 0)
      break;
  }
  
  cout<<sum;
  
  return 0;
}
