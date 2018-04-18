#include<iostream>

vector<vector<int> > print_concentric(int a)
{
  vector<vector<int> > mat;
  
  
}

int main()
{
  
  vector<vector<int> > sol = print_concentric(3);
  
  for(int i = 0; i < sol.size())
  {
    cout<<"\n";
    for(int j = 0; j < sol[0].size())
      cout<<sol[i][j]<<" ";
  }
  return 0;
}
