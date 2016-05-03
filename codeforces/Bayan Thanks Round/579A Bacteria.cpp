#include<iostream>

using namespace std;

int main()
{
  long o;
  cin>>o;
  
  long res = 0;
  
  while(o)
  {
    res = res + o%2;
    o = o/2;
  }
  
  cout<<res;
  
  return 0;
}
