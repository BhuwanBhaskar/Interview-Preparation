#include<iostream>

using namespace std;

int main()
{
  int year;
  cin>>year;
  
  for(int i = year+1; i < 10000; i++)
  {
    //find whether i has all unik digits
    int number[10] = {0};
    int n = i;
    bool fnd = true;
    while(n != 0)
    {
      if(number[n%10])
      {
        fnd = false;
        break;
      }
        
      number[n%10] = 1;
      n /= 10;
    }
    if(fnd)
    {
      cout<<i;
      return 0;
    }
  }
}
