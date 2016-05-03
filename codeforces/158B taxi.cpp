#include<iostream>

using namespace std;

int main()
{
  int n, g1 = 0,g2 = 0,g3 = 0,g4 = 0;
  
  cin>>n;
  int temp;
  for(int i = 0; i < n; i++)
  {
    cin>>temp;
    
    if(temp == 1)
      g1++;
    else if(temp == 2)
      g2++;
    else if(temp == 3)
      g3++;
    else
      g4++;
  }
  
  int cnt = g4 + g3;
  
  //accomodate 1s and 3s group first

  if(g1 <= g3)
    g1 = 0;
  else
    g1 = g1-g3;
    
  //accomodate 1s and 2s group 
  while(g1 > 0 && g2 > 0)
  {
    cnt += 1;
    g2--;
    g1 -= 2;
  }
  
  if(g1 <=0 && g2 <= 0)
  {
    cout<<cnt;
    return 0;
  }
  
  else if(g2 <= 0)
  {
    if(g1%4 == 0)
      cnt += g1/4;
    else 
      cnt +=  g1/4+1;
  } 
  else
  {
    if(g2%2 == 0)
      cnt += g2*2/4;
    else 
      cnt += ((g2-1)*2)/4+1;
  }
  
  cout<<cnt; 
  return 0;
}
