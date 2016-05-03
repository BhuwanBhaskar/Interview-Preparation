//https://www.codechef.com/problems/MARCHA1

#include<bits/stdc++.h>
using namespace std;

int wallet[20];
bool is_possible(long m, int beg, int end){
	
	int sum = 0;
	for(int i = beg; i < end; i++){
		sum = m-wallet[i];
		if(sum == 0){
			return true;
		}else if(sum > 0){
			if(is_possible(sum,i+1,end)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	
	int t;
	cin>>t;
	
	for(int i = 0; i < t; i++){
		int n,temp;
		long m;
		cin>>n>>m;
		
		for(int i = 0; i < n; i++){
			cin>>wallet[i];
		}
		
		if(is_possible(m,0,n)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	return 0;
}
