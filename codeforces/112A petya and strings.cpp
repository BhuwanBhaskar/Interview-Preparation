#include<iostream>
#include<cctype>
using namespace std;

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  
  int i = 0;
  while(i < s1.length() && tolower(s1[i]) == tolower(s2[i]))
    i++;
  
  if(i == s1.length())
    cout<<0;
  else if(tolower(s1[i]) < tolower(s2[i]))
    cout<<-1;
  else
    cout<<1;
  return 0;
}
