#include<iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  
  int b = 1;
  int offset = 1;
  
  while(n > 5)
  {
    n -= 4;
    n /= 2;
  }
  
  if(n == 1)
    cout<<"Sheldon";
  else if(n == 2)
    cout<<"Leonard";
  else if(n == 3)
    cout<<"Penny";
  else if(n == 4)
    cout<<"Rajesh";
  else if(n == 5)
    cout<<"Howard";
  
  return 0;
}
