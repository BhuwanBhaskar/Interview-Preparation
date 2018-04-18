#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

//coins is a map which stores gold coins as a key and dollars as a value
long long find_coins(long long n , map<long long , long long> &coins)
{
  if(n < 12)
    return n;
    
  if(coins[n] >= 1)
    return coins[n];
  
  coins[n] = find_coins(n/2,coins)+find_coins(n/3,coins)+find_coins(n/4,coins);
  return coins[n];
}

int main()
{
  long long n;
  map<long long , long long> coins;
  while(scanf("%lld",&n) > 0)
  { 
    long long total = find_coins(n,coins);
  
    cout<<total<<endl;
  }
  
  return 0;
}
