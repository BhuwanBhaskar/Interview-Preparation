#include<iostream>
using namespace std;

//char tolower(char )
bool isVowel(char c)
{
  char x = tolower(c);

  if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
    return true;
  
  return false;
}

int main()
{
  string str,ostr = "";
  cin>>str;
  int l = str.length();
  
  for(int i = 0; i < l; i++)
  {
    if(isVowel(str[i]))
      continue;
    else
    {
      ostr = ostr+"."+(char)tolower(str[i]);
    }
  }
  
  cout<<ostr;
  
  return 0;
}
