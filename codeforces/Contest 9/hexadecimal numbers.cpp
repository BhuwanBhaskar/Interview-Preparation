//http://codeforces.com/contest/9/problem/C

#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

long add_1(long i){
	
	string str;
	stringstream ss;
	ss<<i;
	ss>>str;
	
	//adding 1 to string
	int k = str.length()-1;
	bool carry = true;
	while(k >= 0){
		if(carry && str[k] == '1'){
			carry = true;
			str[k] = '0';

			if(k <= 0){
				//cout<<"it iszeor : "<<k<<"\n";
				break;
			}else
				k--;
		}else if(!carry || (carry & str[k] == '0') ){
			str[k] = '1';
			break;
		}
		//cout<<k<<endl;
	}
	//cout<<str<<endl;
	if(carry && k == 0){
		str[0] = '0';
		str.insert(k,"1");
	}
	//cout<<str;
	stringstream ssb;
	ssb<<str<<endl;
	long ret;
	ssb>>ret;
	//cout<<"ret : "<<ret<<endl;
	return ret;
}

int main(){
	
	long n;
	cin>>n;
	
	int cnt = 0;
	long i = 1;
	while(i <= n){
		i = add_1(i);
		//break;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
