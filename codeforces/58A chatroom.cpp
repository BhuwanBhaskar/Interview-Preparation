#include<iostream>

using namespace std;

int main()
{
  string hello;
  cin>>hello;
  
  if(hello.length() < 5)
  {
    cout<<"NO";
    return 0;
  }
  
  int i = 0;
  int seen = 0;
  //advancing pointer till we see 'h'
  while(i < hello.length() && hello[i] != 'h')
    i++;
  if(hello[i] == 'h')
    seen = 1;
 // cout<<hello[i]<<endl;
  while(seen == 1 && i < hello.length() && hello[i] != 'e')
    i++;
  if(hello[i] == 'e')
    seen = 2;
  //cout<<hello[i]<<endl;
  while(seen == 2 && i < hello.length() && hello[i] != 'l')
    i++;
  if(hello[i] == 'l')
    seen = 3;
  //cout<<hello[i]<<endl;
  i++;
  while(seen == 3 && i < hello.length() && hello[i] != 'l')
    i++;
  if(hello[i] == 'l')
    seen = 4;
  //cout<<hello[i]<<endl;
  while(seen == 4 && i < hello.length() && hello[i] != 'o')
    i++;
  if(hello[i] == 'o')
    seen = 5;
  //cout<<hello[i]<<endl;
  if(seen == 5 && i < hello.length())
  {
    cout<<"YES";
    return 0;
  }
  else
  {
    cout<<"NO";
    return 0;
  }
}
