#include<iostream>

using namespace std;

int main()
{
  int n;
  int p,q,cnt = 0;
  cin>>n;
  
  while(n >= 1)
  {
    cin>>p>>q;
    if(q-p >= 2)
      cnt++;
    n--;
  }
  cout<<cnt;
}
