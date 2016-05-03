#include<iostream>
using namespace std;

int brute_force(int k, int l, int m, int n, int d, int *cnt)
{
  //int left = min(min(k,l),min(m,n));
  
  for(int i = 1; i <= d; i++)
  {
    if(i%k == 0)
      *cnt++;
    else if(i%l == 0)
      *cnt++;
    else if(i%m == 0)
      *cnt++;
    else if(i%n == 0)
      *cnt++;
  }
}

//a <= b
int gcd(int a, int b)
{
  if(a == 0)
    return b;
    
  return gcd(b%a,a);
}

int lcm(int a, int b)
{
  return (a*b)/gcd(a,b);
}

int lcm(int a, int b, int c)
{
  return lcm(a,lcm(b,c));
}

int lcm(int a, int b, int c, int d)
{
  return lcm(lcm(a,b),lcm(c,d));
}
int main()
{
  int k,l,m,n,d,cnt = 0;
  cin>>k>>l>>m>>n>>d;
  
  if(k == 1 || l == 1 || m == 1 || n == 1)
  {
    cout<<d;
    return 0;
  }
  
  //cout<<brute_force(k,l,m,n,d,&cnt);
  
  //let's use some brain
  //think of problem in terms of set problem using veinn diagram
  //let's find dragons which are divisible by atleast 1,2,3 and 4 ways then it's simple
  
  int n1 = d/k + d/l + d/m + d/n;  //dragons hurt by atleast one way
  int n2 = d/lcm(k,l)+d/lcm(k,m)+d/lcm(k,n)+d/lcm(l,m)+d/lcm(l,n)+d/lcm(m,n); //hurt by atleast two ways
  int n3 = d/lcm(k,l,m)+d/lcm(l,m,n)+d/lcm(k,l,n)+d/lcm(k,m,n); //hurt by atleast three ways
  int n4 = d/lcm(k,l,m,n); //hurt by atleast four ways; intersection of all sets
  cnt = (n1-n2) + (n3-n4); 
  cout<<cnt;
  return 0;
}
