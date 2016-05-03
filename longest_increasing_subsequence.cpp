#include<iostream>

using namespace std;

int lis(int arr[],int n)
{
  cout<<"comp1\n";
  int sol[n];

  for(int i = 0; i < n; i++)
    sol[i] = 1;
  cout<<"comp2\n";
  for(int i = 1; i < n; i++)
  {
    int c = 0;
    for(int j = 0; j < i-1; j++)
    {
      if(arr[i] > arr[j])
        c++;
    }

    if(c >= 1)
      sol[i] = sol[i-1] + 1;
    else
      sol[i] = sol[i-1];
  }

  return sol[n-1];
}

int main()
{
  int arr[] = {14,22,9,13,15,20,41,60};
  //lis(arr,8);
  cout<<"\n"<<lis(arr,8)<<endl;
  return 0;
}
