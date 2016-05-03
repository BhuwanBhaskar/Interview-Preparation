#include<iostream>

using namespace std;

int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	return gcd(b%a,a);
}
int main(){
	
	int y,w;
	cin>>y>>w;
	
	int maxi = y > w ? y : w;
	int diff = 6-maxi+1;
	//cout<<diff<<endl;
	if(diff != 0){
		int g = gcd(diff,6);
		//cout<<g<<endl;
		cout<<diff/g<<"/"<<6/g<<endl;
	}else{
		cout<<"0/1"<<endl;
	}
	return 0;
}
