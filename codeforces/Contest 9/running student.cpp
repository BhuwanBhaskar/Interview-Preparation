//http://codeforces.com/contest/9/problem/B

#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	double vb,vs;
	cin>>n>>vb>>vs;
	
	double stops[n];

	for(int i = 0; i < n; i++){
		cin>>stops[i];
	}
	double dx,dy;
	cin>>dx>>dy;
	
	double distb = 0,distr = 0,time = 0;
	double min = DBL_MAX;
	int ret = 0;
	for(int i = n-1; i >= 1; i--){
		distr = sqrt((dx-stops[i])*(dx-stops[i]) + dy*dy);
		distb = stops[i];

		time = distb/vb + distr/vs;
		//cout<<distb<<"  : "<<distr<<" => "<<time<<"\n";
		if(time < min){
			min = time;
			ret = i+1;
		}
	}
	
	cout<<ret<<endl;
	return 0;
}
