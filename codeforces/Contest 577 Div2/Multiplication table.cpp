#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  long n,x;
  cin>>n>>x;
  int cnt = 0;
//  for(int i = 1; i <= n; i++)
//  {
//    for(int j  = 1; j <= n; j++)
//    {
//      if(i*j == x)
//      {
//        cout<<i<<" "<<j<<endl;
//        cnt++;
//      }
//    }
//  }
//  cout<<cnt<<endl;
//  cnt = 0;
  //count number of unique factors !!!  (we don't need only prime)
//  if(x%2)  // x is prime number => it means factors of x are 1 and x;
//  {
//    if(x <= n)
//      cout<<2;
//    else
//      cout<<0;
//    return 0;
//  }
  if(x == 1 || (n == 1 && x == 1))
  {
    cout<<1;
    return 0;
  }
  else if(n == 1 && x > 1)
  {
    cout<<0;
    return 0;
  }
  //we are checking for x >= 2
  for(long i = 2; i <= n && i <= x/2; i++)
    if(x%i == 0 && x/i <= n)
    {
      //cout<<i<<" "<<x/i<<endl;
      cnt++;
    }
  
  if(n >= x)
    cnt += 2;   //let's include x itself and 1
      
  cout<<cnt;
  
  return 0;
}
