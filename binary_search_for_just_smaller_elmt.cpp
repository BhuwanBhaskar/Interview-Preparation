#include<iostream>

using namespace std;

long binary_search_small(int friends[], long n, long key)
{
	long left = 0, right = n-1;
	long middle ;

	while(left <= right)
	{
		middle = left + (right-left)/2;
		if(key == friends[middle])
			return middle;
		if(right - left == 1)
			return left;
		else if(key < friends[middle])
			right = middle;
		else if(key > friends[middle])
			left = middle;
	}
	return -1;
}

int main()
{
	int a[] = {1,3,5,7,9,11,11,13,13,15,17};
	cout<<binary_search_small(a,sizeof(a)/sizeof(a[0]), -3);

	return 0;
}
