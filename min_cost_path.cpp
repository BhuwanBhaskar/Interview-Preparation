#include<iostream>

using namespace std;

#define R 3
#define C 3

int min(int x, int y, int z)
{
  if(x < y && x < z)
    return x;
  else if(y < x && y < z)
    return y;
  else
    return z;
}

int min_cost(int path[][3],int x, int y)
{
  int sol[R][C];
  
  sol[0][0] = path[0][0];
  
  for(int i = 1; i <= x; i++)
    sol[i][0] = sol[i-1][0] + path[i][0];
  for(int j = 1; j <= y; j++)
    sol[0][j] = sol[0][j-1] + path[0][j];
    
  for(int i = 1; i <= x; i++)
    for(int j = 1; j <= y; j++)
      sol[i][j] = min(sol[i-1][j-1],sol[i][j-1],sol[i-1][j]) + path[i][j];
  
  return sol[x][y];
}

int main()
{
  int path[][3] =  { {1, 2, 3},
                    {4, 8, 2},
                    {1, 5, 3} 
                   };
  
  cout<<min_cost(path,2,1)<<endl;
  return 0;
}
