#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;


int partition(vector<int> &a , int beg , int end)
{
  int i= beg ,j = end+1;
  int pivot = a[beg];
  
  for(;;)
  {
    while(a[++i] < pivot)
      if(i >= end)
        break;
    while(a[--j] > pivot)
      if(j <= beg)
        break;
    if(i >= j)
      break;
    else
    {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp; 
    }
    
  }
  
  if(j == beg)
    return j;
  
  int temp = pivot;
  a[beg] = a[j];
  a[j] = temp;
  
  return j;
}
void quick_sort(vector<int> &a , int i , int j)
{
  if(i > j)
    return;
    
    int pivot = partition(a,i,j);
    quick_sort(a,i,pivot-1);
    quick_sort(a,pivot+1,j);
}

int main()
{
  int arr[] = {4,1,3,2};
  vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0]));
  
  quick_sort(vec,0,vec.size()-1);
  
  copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
  
  return 0;
}
