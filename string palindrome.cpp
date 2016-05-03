#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

int is_pali(string str)
{
  int b = 0,e = str.length()-1;
  
  while(b < e)
  {
    while(b < e && !isalnum(str[b]))
      b++;
      
    while(b < e && !isalnum(str[e]))
      e--;
      
    if(tolower(str[b]) != tolower(str[e]))
      return 0;
      
    b++;
    e--;   
  }
  return 1;
}

int main()
{
  
  cout<<is_pali("A man, a plan, a cdnal: Panama")<<endl;
}
