#include<iostream>

using namespace std;
#define N 11

int visited[N] = {0};
int stack[N] = {0};
int mark[N] = {0};
int mat[N][N];
int cycle = 0;

void rec_dfs(int st)
{
  if(!visited[st])
  {
    visited[st] = stack[st] = 1;
    
    for(int c = 0; c < N; c++)
    {
      if(mat[st][c])
      {
        if(!visited[c])
          rec_dfs(c);
        if(stack[c])
        {
          mark[c] = 1;
          stack[c] = 0;
          cycle = 1;
          return;
        }
      }
    }
  }
  stack[st] = 0;
}

void dfs(int st)
{
  for(int i = st; i < N; i++)
  {
    if(!visited[i])
      rec_dfs(i);
    if(cycle)
      return;
  }
}

int main()
{
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
      mat[i][j] = 0;
  }
  
  int st,end,ne;
  cin>>ne;
  
  for(int i = 0; i < ne; i++)
  {
    cin>>st>>end;
    mat[st][end] = 1;
  }
  
  dfs(1);
  
  for(int i = 0; i < N; i++)
    if(mark[i])
      cout<<i<<"\t";
  
  return 0;
}
