#include<iostream>

using namespace std;

int xlen(string str)
{
  int i = 0;
  while(str[i] != '\0')
    i++;
  return i;
}

int main()
{
  int n;
  cin >>n;
  
  string str;
  
  for(int i = 0; i< n; i++)
  {
    cin>>str;
    int l = xlen(str);
    
    if(l > 10)
    {
      cout<<str[0]<<l-2<<str[l-1]<<endl;
    }
    else
      cout<<str<<endl;
  }
}
