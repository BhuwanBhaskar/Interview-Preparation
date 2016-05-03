#include<iostream>

using namespace std;

void processPat(string &pat, int mat[])
{
  int i = 0;
  int m = 0;
  
  mat[i++] = 0;
  
  //job is to fill mat[] such that mat[i] contains no. of matched chars (of prefix)
  //ex. pat = "ABABCABAB" then mat[] = {0,0,1,2,0,1,2,3,4}
  while(i < pat.length())
  {
    //keep on matching previous char with next ones until we find mismatch..ex aaaaabaaaa
    if(pat[i] == pat[m])
      mat[i++] = ++m;
    //when we do find mismatch
    else
    {
      if(m != 0)
        m = mat[m-1];   //backtrack to first matching prefix (with next char at i)
      else              // if we backtracked to first char, then let's start again (m = 0) !!!
        mat[i++] = 0;   
    }
  }
}
void matchPattern(string &txt, string &pat)
{
  int p = pat.length();
  int t = txt.length();
  int matched[p];
    
  processPat(pat,matched);
  
  for(int i = 0; i < p; i++)
    cout<<matched[i]<<" ";
    
  int i = 0, j = 0;
  while(i < txt.length())
  {
    if(pat[j++] == txt[i++])  
      ;
    
    if(j == p)
    {
      cout<<"\nPattern found at : "<<i-j<<endl;
      j = matched[p-1];
    }
    
    //we have matched j chars already but next match failed so
    else if(pat[j] != txt[i])
    {
      if(j != 0)    //let's go back to first j which will match with next i
        j = matched[j-1];
      else   //sorry we couldn't find match...leave it start again from j = 0
        i++;
    }
  }
}

int main()
{
  string txt = "AAAABAAAAABA";
  string pat = "AAAB";
  
  matchPattern(txt,pat);
  
  return 0;
}
