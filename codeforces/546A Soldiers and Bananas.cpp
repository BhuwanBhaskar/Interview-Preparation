#include<iostream>
using namespace std;

int main(){
	
	long k,n,w;
	cin>>k>>n>>w;
	
	long sum = 0;
	long i = 1;
	while(i <= w){
		sum += i*k;
		i++;
	}
	if(sum < n){
		cout<<0<<endl;
	}else
		cout<<sum-n<<endl;
	return 0;
}
