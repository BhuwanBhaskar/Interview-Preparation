#include<iostream>
#include<cmath>

using namespace std;
#define DIFF 100000

//****WE CAN'T USE STL ELEMENTS in this files...throws RUN TIME ERROR may be due to allocation of STL 
//let us get all prime numbers from 1 to sqroot(N) in primes vector
//It is optimized version of sieve,we have excluded all even numbers from our list
//so that we don't have to cross them again and again ..also for space optimization
//i have used bitset
//stores prime numbers till squareroot (N) using sieve of Erosthenes
int sieve(int n, int primes[])
{
  int range = floor(sqrt(n));
  int k = floor(sqrt(range));
  bool composites[DIFF];
  
  for(int i = 2; i < DIFF; i++)
  {
    primes[i] = 0;
    composites[i] = false;
  }
  
  for(int i = 2; i <= k; ++i)
  {
    if(!composites[i])
    {
      //we need to cross out multiples of 2*i+3 (3,5,7,9..) since we have eliminated even so
      for(int j = i*i; j <= range; j+=i)
      {
        composites[j] = true;
      }
    }
  }
  //include only even prime number
  int cnt = 0;
  for(int j=2; j <= range; ++j)
    if(!composites[j])
      primes[cnt++] = j;   //here we are including odd prime numbers !!
  
//  for(int i = 0; i < cnt; i++)
//    cout<<primes[i]<<" ";   
  
  return cnt;
}

void segmented_sieve(int begin, int end, int primes[], int size)
{
  bool prime[DIFF] ;   // let us assume that there are 100000 prime numbers in[begin,end] !possible :)
  
  for(int i = 0; i < DIFF; i++)
    prime[i] = true;
    
  for(int i = 0; i < size; ++i)
  {
    int nearest_composite = primes[i]*(begin/primes[i]); //find nearest composite to begin 
    //cout<<nearest_composite<<endl;
    for(int j = nearest_composite; j <= end; j += primes[i])
    {
      if(j < begin)
        continue;
      prime[j-begin] = false;  // Indexing is cruel !!! while printing we need to take care
    }
  }
  //start printing..we should print numbers in primes vector first if it is in range
  for(int i = 0; i < size; ++i)
  {
    if(primes[i] >= begin && primes[i] <= end)
      cout<<primes[i]<<endl;
  }
  //we will only access what is required by the range[begin,end]
  for(int i = 0; i < end-begin+1; ++i)
  {
    if(prime[i] && (i+begin) != 1)  // does not print 1 it is not a prime number
      cout<<begin+i<<endl;
  }
}

int main()
{
  int t,m,n;
  cin>>t;
  
  for(int k = 1; k <= t; k++)
  {
    cin>>m>>n;
    if(m == 1 && n == 1)
    {
      cout<<endl;
      continue;
    }
    int primes[DIFF] = {0};
    int total = sieve(n,primes);  //populate all primes numbers till sqroot(n) in primes vector
    //cout<<total<<endl;
    //we can now use segmented sieve to find out and print all prime numbers from m to n;
    segmented_sieve(m,n,primes,total);
  } 
  return 0;
}
