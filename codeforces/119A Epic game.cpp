#include<iostream>

using namespace std;

int gcd(int a, int b)
{
  if(a == 0)
    return b;
  return gcd(b%a,a);
}

int main()
{
  int a,b,n,g,turn;
  cin>>a>>b>>n;
  turn = a;
  bool simon = true;
  
  while(true)
  {
    g = gcd(turn,n);
    //cout<<turn<<" "<<n<<" "<<g<<" "<<n<<endl;
    if(g > n)
    {
      if(simon)
        cout<<1;
      else
        cout<<0;
        
      return 0;
    }
    
    n = n-g;
    if(simon)
    {
      simon = false;
      turn = b;
    }
    else
    {
      simon = true;
      turn = a;
    }
  }
  
  return 0;
}
