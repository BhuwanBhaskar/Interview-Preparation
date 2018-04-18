#include<iostream>
#include<map>
#include<cmath>

using namespace std;

map<int,int> primes;

int sieve(int n)
{
  int prim[n+1];
  
    for(int i = 0,j = 0; i <= n; i++,j++)
      prim[j] = i;
    
    for(long k = 2; k*k <= n; k++)
      for(long j = k*k; j <= n; j += k)
      {
        prim[j] = 0;
      }
   primes.insert(pair<int,int>(2,1));
   for(int i = 3; i <= n; i+=2)
    if(prim[i])
      primes.insert(pair<int,int>(i,1));
}

int main()
{
  long t,m,n;
  cin>>t;
  
  sieve(100000);
    
  for(int k = 0; k < t; k++)
  {
    cin>>m>>n;
    
    if(m == 1 && n == 1)
    {
      cout<<endl;
      continue;
    }
      
    if(m == 1)
      m++;
    
    if(m <= 2)
    {
      cout<<2<<endl;
      m = 3;
    }
    
    if(n <= 100000)
    {
      map<int,int>:: iterator itub = primes.upper_bound(m);
      map<int,int>:: iterator itub2 = primes.upper_bound(n);
      while(itub != itub2)
      {
        cout<<itub->first;
        itub++;
      }
      return 0;
    }
    else if(m%2 == 0)
      m = m+1;
     
    for(int i = m; i <= n; i += 2)
    {
      
      bool check = true;
      bool prime = true;
      
      if(i <= 100000 && primes.find(i) != primes.end())
      {
        cout<<i<<endl;
        continue;
      }
        
      map<int,int>:: iterator itlb,itub,temp;
      itub = primes.upper_bound(i);
      temp = itub;
      itlb = --temp;
      //cout<<itub->first<<" "<<i<<" "<<itlb->first<<endl;
      if(i > itlb->first && i < itub->first)
      {
        
        continue;
      }
      int sqi = (int)sqrt(i);  
      map<int,int>::iterator it = primes.begin();
      for(; it != primes.end() && (it->first) <= sqi; it++)
      {
        //cout<<" incoming ";
        if((i%(it->first) == 0))
        {
          prime = false;
          check = false;
          break;
        }
      }
      if(check)
      {
        //cout<<" Checking for : "<<i<<endl;
        //map<int,int>::reverse_iterator rit = primes.rbegin();
        
        for(long j = 100000; j <= sqi; j++)
        {
          if(i%j == 0)
          {
           // nprimes[i] = 1;
            prime = false;
            break;
          }
        }
      }
      
      if(prime)
      {
        //cout<<" Inserting  : "<<i<<endl;
        primes[i] = 1;
        cout<<i<<endl;
      }
    }
    cout<<endl;
  }
  
  return 0;
}
