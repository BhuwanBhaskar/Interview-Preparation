#include<iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  
  int lucky[] = {4,7,47,74,447,474,477,744,747,777};
  int s = sizeof(lucky)/sizeof(lucky[0]);
  
  for(int i = 0; i < s && n >= lucky[i] ; i++)
    if(n%lucky[i] == 0)
    {
      cout<<"YES";
      return 0;
    }
  
  cout<<"NO";
  return 0;
}
