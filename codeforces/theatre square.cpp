#include<iostream>

using namespace std;

//ceil(m/a) + ceil(n/a) are perfect for job
//ceil(m/a) = (m+a-1)/a
unsigned long long cuts(long length , long measure)
{
  unsigned long long mod = length%measure;
  bool cuttable = measure < length;

  if(mod && cuttable)
    return length/measure + 1;
  else if(!mod && cuttable)
    return length/measure;
  else
    return 1;

}

int main()
{
  unsigned long long n , m , a;

  cin>>n>>m>>a;

  cout<<cuts(n,a)*cuts(m,a)<<endl;

  return 0;
}
