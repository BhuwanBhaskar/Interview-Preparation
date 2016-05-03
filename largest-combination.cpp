#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(int x , int y)
{
  int n1,n2;
  n1 = n2 = 0;
  int tx = x;
  int ty = y;
  while(x)
  {
    x = x/10;
    n1++;
  }
  while(y)
  {
    y = y/10;
    n2++;
  }
  
  int n1p = pow(10,n1);
  int n2p = pow(10,n2);
  //cout<<"comparing"<<tx << " and "<<ty<<endl;
  return (ty*n1p + tx < tx*n2p + ty);
    
}

string largest_combi(vector<int> a)
{
  string temp,s1;
  temp = "";
  sort(a.begin(),a.end(),comp);
  
  for(int i = 0; i < a.size(); i++)
  {
    //cout<<a[i]<<"\t";
    stringstream itoa;
    itoa << a[i];
    itoa >> s1;
    temp = temp+s1;
  }
  
  return temp;
}

int main()
{
  int a[] = {472, 663, 964, 722, 485, 852, 635, 4, 368, 676, 319, 412 };
  vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
  string str = largest_combi(vec);
  
  cout<< str<<endl;
  
  return 0;
}
