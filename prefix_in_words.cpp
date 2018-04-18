#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int comp(string a, string b)
{
  return a.length() >= b.length() ? 0 : 1;
}

string find_prefix(vector<string> words)
{
  int nw = words.size();
  string prefix = "";
  cout<<"enter\n";
  sort(words.begin(),words.end(),comp);
  prefix = words[0];  //word[0] is string of shortest length;
  cout<<"sort\n";
  copy(words.begin(),words.end(),ostream_iterator<string>(cout,"  "));
  
  for(int i = prefix.length(); i >= 0 ; i--)
  {
    prefix = prefix.substr(0,i);
    cout<<prefix<<endl;
    int j;
    for(j = 1; j < nw; j++)
      if(words[j].substr(0,i) != prefix)
        break;
    if(j == nw)
      return prefix;
  }
  return " ";
}

int value(char r)
{
  switch(r)
  {
    case 'I': return 1;
    case 'X': return 10;
    case 'V': return 5;
    case 'M': return 1000;
    case 'D': return 500;
    case 'L': return 50;
    case 'C': return 100;
    default : return -1;
  }
}

int roman_int(string roman)
{
  int res = 0;
  
  for(int i = roman.length()-1; i >= 0; i--)
  {
    if(roman[i-1] == 'I' && (roman[i] == 'V' || roman[i] == 'X'))
      res = res + value(roman[i--])-1;
    else if(roman[i-1] == 'X' && (roman[i] == 'C' || roman[i] == 'L'))
      res = res + value(roman[i--])-10;
    else if(roman[i-1] == 'C' && (roman[i] == 'D' || roman[i] == 'M'))
      res = res + value(roman[i--])-100;
    else
      res = res + value(roman[i]);
    //cout<<res<<endl;
  }
  return res;
}

int main()
{
  //string words[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
  //vector<string> vec(words,words+sizeof(words)/sizeof(words[0]));
  
  //cout<<find_prefix(vec)<<endl;
  string roman = "MMXIV";
  cout<<roman_int(roman)<<endl;
  return 0;
}

