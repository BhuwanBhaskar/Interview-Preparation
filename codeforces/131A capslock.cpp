#include<iostream>

using namespace std;

int main()
{
  string in;
  cin>>in;
  
  int i;
  for(i = 1; i < in.length(); i++)
  {
    if(!isupper(in[i]))
      break;
  }
  
  //if i == in.length() then all letters from i = 1 to end are uppercase
  //cout<<i<<endl;
  
  if((!isupper(in[0]) &&  i == in.length()) || (isupper(in[0]) &&  i == in.length()) )
  {
    //cout<<"entr\n";
    //first char is lower and rest is upper
    if(!isupper(in[0]) &&  i == in.length())
    {
      in[0] = (char)toupper(in[0]);
      for(int j = 1; j < in.length(); j++)
        in[j] = (char)tolower(in[j]);
    }
    else
    {
      for(int j = 0; j < in.length(); j++)
        in[j] = (char)tolower(in[j]);
    }
    
  }
  cout<<in<<endl;
  return 0;
  
    
}
