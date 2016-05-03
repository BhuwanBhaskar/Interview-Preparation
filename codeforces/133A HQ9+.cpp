#include<iostream>

using namespace std;

int main()
{
  string hq9;
  cin>>hq9;
  
  int i = 0;
  while(i < hq9.length())
  {
    if(hq9[i] == 'H' || hq9[i] == 'Q' || hq9[i] == '9')
    {
      cout<<"YES";
      break;
    }
    //if(hq9[i] == '+')
    {
     // hq9[i+1] = hq9[i+1]+1;
      //cout<<hq9[i+1]<<endl;
    }
      
    i++;
  }
  if(i == hq9.length())
    cout<<"NO";
    
  return 0;
}
