#include<iostream>

using namespace std;

unsigned long long int fact(int n)
{
  if( n == 0 || n == 1)
    return n;
  return n*fact(n-1);
}
int no_fives(int n,int i)
{
  int cnt = 0;
  int temp = n;
  
  if(temp%i == 0)
    return temp/i;
  temp = temp-temp%i;
  return temp/i;
}

int no_zeroes(int n)
{
  int temp = n;
  int cnt = 0;
  int i = 5;
  while(temp >= i)
  {
    cnt = cnt + no_fives(n,i);
    i = i*5;
  }
//  if(n%25 == 0)
//    return n/25 + no_fives(n);
//  n = n-n%25;
  //return n/25 + no_fives(temp);
  return cnt;
}

int main()
{
  //for(int i = 0; i <= 25; i++)
    //cout<<i<<"=>"<<fact(i)<<" ==> "<<no_fives(i)<<endl;
  cout<<no_zeroes(9247)<<endl;
  cout<<no_zeroes(9247);  
  return 0;
}
