#include<iostream>

using namespace std;

int main()
{
  int n = 0;
  
  cin>>n;
  
  int* mat[n];
  
  for(int i = 0; i < n; i++)
  {
    mat[i] = new int*[n];
  }
}
