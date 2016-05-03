#include<iostream>

using namespace std;

int main()
{
  int n,out = 0;
  cin>>n;
  
  string st;
  while(n != 0)
  {
    cin>>st;
    
    if(st[0] == 'X' && st[1] == '+' || st[0] == '+')
      out++;
    else
      out--;
    n--;
  }
  
  cout<<out<<endl;
}
