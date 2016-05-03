#include<iostream>

using namespace std;

int min_coin(int coins[], int val, int n)
{
  int sol[val+1] = {0};
  sol[0] = 1; //base case
  
  //traverse through all coins
  for(int i = 0; i < n; i++)
    //pick a coin less than val , find out needed coin for this val
    for(int j = coins[i]; j <= val; j++)
    {
      sol[j] += sol[j-coins[i]];
    }
  
  return sol[val];
}

int main()
{
  int coins[] = {2,5,3,6};
  cout<<min_coin(coins,10,sizeof(coins)/sizeof(coins[0]))<<endl;
  return 0;
}
