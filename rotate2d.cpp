#include<iostream>
#include<vector>
using namespace std;

void rotate_2d(vector<vector<int> > &a)
{
  int k = a[0].size();
  if(k%2)
    k = (k-1)/2;
  else
    k = k/2;
    
  for(int i = 0; i < a.size(); i++)
  {
    int n = a[i].size();
    for(int j = 0; j < k; j++ )
    {
      //cout<<"Bef : "<<a[i][j]<<" "<<a[i][n-j-1]<<endl;
      int temp = a[i][j];
      a[i][j] = a[i][n-j-1];
      a[i][n-j-1] = temp;
      //cout<<"After : "<<a[i][j]<<" "<<a[i][n-j-1]<<endl;
    }
  }
  
 for(int i = 0; i < a.size(); i++)
  {
    cout<<"\n";
    for(int j = 0; j < a[i].size(); j++)
      cout<<a[i][j]<<"\t";
  }
  
  int n = a[0].size();
  for(int i = 0; i < n; i++)
  {   
    for(int j = 0; j < n-i; j++)
    {
      cout<<i<<j<<endl;
      cout<<"Bef : "<<a[i][j]<<" "<<a[n-j-1][n-i-1]<<endl;
      int temp = a[i][j];
      a[i][j] = a[n-j-1][n-i-1];
      a[n-j-1][n-i-1] = temp;
      cout<<"after : "<<a[i][j]<<" "<<a[n-j-1][n-i-1]<<endl;
    }
  }
}

int main()
{
  vector<vector<int> >vec;
//  vector<int> row1;
//  row1.push_back(1);
//  row1.push_back(2);
//  vector<int> row2,row3;
//  row1.push_back(3);
//  row2.push_back(4);
//  row2.push_back(5);
//  row2.push_back(6);
//  row3.push_back(7);
//  row3.push_back(8);
//  row3.push_back(9);
//  vec.push_back(row1);
//  vec.push_back(row2);
//  vec.push_back(row3);
  
  int a1[] = {31, 32, 228, 333};
  int a2[] = {79, 197, 241, 246};
  int a3[] = {77, 84, 126, 337};
  int a4[] = {110, 291, 356, 371};
  
  vector<int> r1(a1,a1+sizeof(a1)/sizeof(a1[0]));
  vector<int> r2(a2,a2+sizeof(a1)/sizeof(a1[0]));
  vector<int> r3(a3,a3+sizeof(a1)/sizeof(a1[0]));
  vector<int> r4(a4,a4+sizeof(a1)/sizeof(a1[0]));
  vec.push_back(r1);
  vec.push_back(r2);
  vec.push_back(r3);
  vec.push_back(r4);
  for(int i = 0; i < vec.size(); i++)
  {
    cout<<"\n";
    for(int j = 0; j < vec[i].size(); j++)
      cout<<vec[i][j]<<"\t";
  }
  cout<<"\n\n";
  rotate_2d(vec);
  
  cout<<"\n\n";
  for(int i = 0; i < vec.size(); i++)
  {
    cout<<"\n";
    for(int j = 0; j < vec[i].size(); j++)
      cout<<vec[i][j]<<"\t";
  }
  return 0;
}
