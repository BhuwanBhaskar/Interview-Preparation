#include<iostream>

using namespace std;

int main()
{
  int alphabet[26] = {0},distinct = 0;
  string name;
  cin>>name;
  
  for(int i = 0; i < name.length(); i++)
    alphabet[name[i]-'a'] = 1;
  
  for(int i = 0; i < 26; i++)
    if(alphabet[i] == 1)
      distinct++;
    
  if(distinct%2 == 0)
    cout<<"CHAT WITH HER!";
  else
    cout<<"IGNORE HIM!";
  
  return 0;
}
