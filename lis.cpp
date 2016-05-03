#include<iostream>

using namespace std;

int lis(int arr[],int n)
{
  int sol[n];

  for(int i = 0; i < n; i++)
    sol[i] = 1;

  for(int i = 1; i < n; i++)
  {
    for(int j = 0; j <= i-1; j++)
    {
    	//if some elmt i is less than all of its previous elmts j then longest increase subsequence may start
    	//from this elmt so it is set to 1. If i is greater than some j then it is already in some subsequence
    	//so lis for i would be to include in j's. 
    	if(arr[i] > arr[j] && sol[i] < sol[j]+1)
					sol[i] = sol[j]+1;
		  else
		  		sol[i] = sol[j];
	  }	  
	}
    
  cout<<"\n";
  for(int i = 0; i < n; i++)
    cout<<sol[i]<<"\t";
  return sol[n-1];
}

int main()
{
  int arr[] = {14,22,9,13,10,23,41,60};
  //lis(arr,8);
  cout<<"\n"<<lis(arr,8)<<endl;
  return 0;
}

