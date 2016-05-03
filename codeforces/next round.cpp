#include<iostream>

using namespace std;

int main()
{
  int n = 0,k = 0;
  cin >>n >>k;
  
  int* ai = new int[n];
  
  for(int i = 0; i < n; i++)
    cin>>ai[i];
  
  if(ai[0] <= 0 )
  {
    cout<<0;
    return 0;
  }
    
  int cnt = 0; 
  while(cnt < n && ai[cnt] > 0 && ai[cnt] >= ai[k-1])
    cnt++;
    
  cout<<cnt;
}
