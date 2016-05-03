#include<iostream>

using namespace std;

long lis(long a[], long n)
{
	long cmax = 1;
	long max = INT_MIN;
	
	for(int i = 1; i < n; i++)
	{
		if(a[i-1] <= a[i])
			cmax += 1;
		else 
			cmax = 1;
		if(max < cmax)
			max = cmax;
	}
	return max;
}

int main()
{
	long n;
	cin>>n;
	
	long a[n];
	for(long i = 0; i < n; i++)
		cin>>a[i];
	
	if(n == 1)
		cout<<1;
	else
		cout<<lis(a,n);
	
	return 0;
}
