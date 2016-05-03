#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int myComp(pair<int,int> p1, pair<int,int> p2)
{
	return p1.first <= p2.first;
}

int main()
{
	int n;
	cin>>n;
	//vector<pair<int,int> > gifts;
	int temp;
	int output[n];
	for(int i = 1; i <= n; i++)
	{
		cin>>temp;
		//pair<int,int> share;
		//share.first = temp;
		//share.second = i;
		output[temp-1] = i;
		//gifts.push_back(share);
	}
	
	//sort(gifts.begin(),gifts.end(),myComp);
	
//	for(int i = 0; i < n; i++)
//		cout<<gifts[i].second<<" ";
//	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<output[i]<<" ";	
	return 0;
}
