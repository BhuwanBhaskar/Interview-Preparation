#include<iostream>
using namespace std;

int ra(int a[],int n)
{
  int x = 0;
  for(int i = 1; i <= n; i++)
    x ^= i;
  cout<<x<<endl;
  for(int i = 0; i < n; i++)
    x ^= a[i];
    
    cout<<x<<endl;
    return x;
}

int main()
{
  int a[] = {4,1,1,2,2};
  cout<<ra(a,5)<<endl;
}
