#include<iostream>

using namespace std;

void swap(string &src, int i, int j){
	
	char temp = src[i];
	src[i] = src[j];
	src[j] = temp;
	
}
string reverse(string &src){
	int len = src.length()-1;
	int i = 0;
	while(i < len){
		swap(src,i,len);
		i++;
		len--;
	}
	//cout<<"swapped "<<src<<endl;
	return src;
}
bool isSame(string src, string dest){
	
	reverse(src);
	
	if(src.length() != dest.length()){
		return false;
	}
	int i = 0;
	while(i < src.length() && src[i] == dest[i]){
		i++;
	}
	if(i == src.length()){
		return true;
	}
	return false;
}
int main(){
	
	string src, dest;
	cin>>src>>dest;
	
	if(isSame(src,dest)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
