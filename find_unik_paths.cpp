#include<iostream>

using namespace std;

long long fact(int n)
{
  long long fact[n];
  
  fact[0] = fact[1] = 1;
  
  for(int i = 2; i <= n; i++)
    fact[i] = i*fact[i-1];
  
  return fact[n];
}

int paths(int a, int b)
{
  int tm = a+b-2;
  int reda = a-1;
  int redb = b-1;
  long long  path = 1;
  //int mx = reda > redb ? reda:redb;
  //int mn = reda < redb ? reda:redb;
  for(int i = tm; i > reda; i--)
    path*=i;
  cout<<path<<"\n";
  //cout<<path<<endl;
  cout<<fact(redb)<<endl;
  //cout<<
  return path/fact(redb);
  
}
int main()
{
  cout<<paths(15,14)<<endl;
  return 0;
}
