#include<iostream>
using namespace std;

int arr[100];
//Think about carry so arr[0] = a/n, arr[1] = a%n
int main()
{

	int a, n, k;
	cin >> a >> n >> k;
	
	int i;
	for (i = 0; i<k; i++)
		arr[i] = 0;
	while (a--)
	{
		arr[0]++;
		int k = 0;
		while (arr[k]>n)
		{
			arr[k] = 0;
			k++;
			arr[k]++;

		}
	}
	for (i = 0; i<k; i++)
	{
		cout << arr[i] << " ";
	}
}