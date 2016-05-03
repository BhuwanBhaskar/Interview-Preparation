#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

/*string long_pali(string str)
{
  int n = str.length();
  bool sol[n][n];
  
  memset(sol,false,sizeof(sol));
  
  
  
  //all one letters are palindrome
  for(int i = 0; i < n; i++)
    sol[i][i] = true;
  
  int mi = 0;
  int max = 1;
   
  //search for two letter palindrome
  for(int i = 1; i < n; i++)
    if(str[i-1] == str[i])
    {
      sol[i-1][i] = true;
      if(mi == 0)
        mi = i-1;
      max = 2;
    }
    else
      sol[i-1][i] = false;
  
    
  //make solution for more than 2 chars case
  //if S(i,j) is palindrome => S(i+1,j-1) must be palindrome and S[i] == S[j]
    if(str.length() <= 2)
      return str.substr(mi,max);
      
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (sol[i+1][j-1] && str[i] == str[j])
            {
                sol[i][j] = true;
 
                if (k > max)
                {
                    mi = i;
                    max = k;
                }
                else if(k == max && i < mi)
                  mi = i;
            }
        }
    }
  
  
  for(int i = 0; i < n; i++)
  {
    cout<<"\n";
    for(int j = 0; j < n; j++)
      cout<<sol[i][j]<<" ";
  }
  return str.substr(mi,max);
}*/

string long_pali(string str)
{
   int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = str.length();
 
    int low, high;
 
    // One by one consider every character as center point of 
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.  
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            else if(high - low + 1 == maxLength && start > low)
            {
              start = low;
            }
            --low;
            ++high;
        }
 
        // Find the longest odd length palindrome with center 
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            else if(high - low + 1 == maxLength && start > low)
            {
              start = low;
            }
            --low;
            ++high;
        }
    }
 
   // printf("Longest palindrome substring is: ");
    //printSubStr(str, start, start + maxLength - 1);
 
    return str.substr(start,maxLength);
}
int main()
{
  cout<<long_pali("bcdaddfgdadsdf")<<endl;
  return 0;
}
