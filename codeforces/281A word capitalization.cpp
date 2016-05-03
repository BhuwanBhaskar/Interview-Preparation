#include<iostream>

using namespace std;

int main()
{
  string str;
  cin>>str;
  
  //check what is ascii val of str[0]
  if(str[0] >= 97)    //first char is in lower case
    str[0] = str[0] - ('a'-'A');
  
  cout<<str;
  
  return 0;
}
