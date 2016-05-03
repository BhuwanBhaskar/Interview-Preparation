#include<iostream>

using namespace std;

int main()
{
  int n = 0;
  
  cin>>n;
  
 // int* mat[n];
  
 // for(int i = 0; i < 3; i++)
 //   mat[i] = new int[3];
  
  int cnt = 0;
  int csum = 0;
  int temp;
  for(int i = 0; i < n; i++)
  {
    csum = 0;
    for(int j = 0; j < 3; j++)
    {
      cin>>temp;
      csum += temp;
    }
    if(csum >= 2)  
      ++cnt; 
  }
  
  cout<<cnt;
  return 0;
}
