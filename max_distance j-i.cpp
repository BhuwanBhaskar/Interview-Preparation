#include<iostream>
#include<vector>

using namespace std;

int max_dist(vector<int> &a)
{
  //lmin will store element at ith index which is smallest from 0..i (left side of i)
  //lmax will store element at jth index which is greatest from j...n-1 (right side of j)
  vector<int>lmin(a.size(),-1),rmax(a.size(),-1);
  int n = a.size();
  
  if(n == 1)
    return 0;
    
  lmin[0] = a[0];
  for(int i = 1; i < n; i++)
    lmin[i] = lmin[i-1] < a[i] ? lmin[i-1] : a[i];
  
  
  rmax[n-1] = a[n-1];
  for(int i = n-2; i >= 0; i--)
    rmax[i] = rmax[i+1] > a[i] ? rmax[i+1] : a[i];
     
  int i,j,diff,max_diff = -1;
  i = j = 0;
  while(i < n && j < n)
  {
    //cout<<"ent";
    if(lmin[i] <= rmax[j]) //all elems 0...i are smaller than j...n-1
    {
      max_diff = max_diff > j-i ? max_diff : j-i;
      //cout<<max_diff<<" "<<j-i<<endl;
      j++;
    }
    else
      i++;
  }
  return max_diff;
}

int main()
{
  int arr[] = {10,10,10,10};
  vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0]));
  
  cout<<max_dist(vec)<<endl;
  
  return 0;
}
