#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int> &a) {
    int n = a.size();
	int k = n-2;
	while(k >= 1 && a[k] > a[k+1])
		k--;
	//k--;
	//find next largest number than a[k] from k+1 to n-1
	//cout<<k<<endl;
	int large = n-1;
	while(large >= 1 && a[k] > a[large] && k != large )
		large--;
	//large--;
	//cout<<large<<endl;
	//swap large number with a[k]
	//cout<<a[k]<<" "<<a[large]<<endl;
	swap(a[k],a[large]);
	/*if(k != large)
	{
	    int temp = a[k];
	    a[k] = a[large];
	    a[large] = temp;
	}*/
	//cout<<a[k]<<" "<<a[large]<<endl;
	//we should begin permutation in k+1...n-1 sequence
	//to permute we just need to sort list in ascending order :)
    if(a.begin()+k+1 < a.end())
	    sort(a.begin()+k+1,a.end());
}

int main()
{
	int a[] = {251};
	vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
	
	nextPermutation(vec);
	
	for(int i = 0; i < vec.size(); i++)
		cout<<vec[i]<<endl;
	return 0;
}
