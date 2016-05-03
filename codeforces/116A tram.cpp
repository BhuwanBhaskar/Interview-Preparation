#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  int n,en,ex,vac = 0,fill = 0;
  
  cin>>n;
  
  while(n != 0)
  {
    n--;
    
    cin>>ex>>en;
    
    vac += ex;
    
    int acc = 0;
    if(vac < en)
    {
      acc = en-vac;
      vac = 0;
    }
    else
      vac -= en;
      
    if(acc > 0)
    {
      fill += acc;
    }
    
    //cout<<vac<<" "<<fill<<endl;
  }
  
  cout<<fill<<endl;
  
  return 0;
}
