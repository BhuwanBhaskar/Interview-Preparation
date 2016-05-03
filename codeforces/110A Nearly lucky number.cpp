#include<iostream>
#include<sstream>
using namespace std;

int main()
{
  long long n;
  cin>>n;
  
  stringstream ss;
  ss << n;
  string lucky;
  ss >> lucky;
  //cout<<lucky;
  
  long cnt = 0;
  for(int i = 0; i < lucky.length(); i++)
    if(lucky[i] == '4' || lucky[i] == '7')
      cnt++;
  
  stringstream ss2;
  ss2<<cnt;
  string luck;
  ss2 >> luck;
  
  int i = 0;
  while(luck[i] == '4' || luck[i] == '7')
    i++;
  
  if(i == luck.length())
    cout<<"YES";
  else
    cout<<"NO";
  
  return 0;
}
