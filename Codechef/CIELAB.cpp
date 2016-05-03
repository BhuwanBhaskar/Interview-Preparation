
//https://www.codechef.com/problems/CIELAB

#include<iostream>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
	int t;
//	cin>>t;
	
	//for(int i = 0; i < t; i++)
	{
		
		int a,b;
		cin>>a>>b;
		
		int diff = a-b;
		//cout<<diff<<endl;
		//change one digit 
		//we can start changing digit from unary position if possible
		int pos = 1;
		while(true){
			if(diff%(10*pos) <= 9 && diff%(10*pos) > 1){
				diff = diff - (pos);
				break;
			}else if(diff%(10*pos) == 1){
				diff = diff + (pos);
				break;
			}else if(diff%(10*pos) == 0){
				diff = diff + pos;
				break;
			}
			pos = pos*10;
		}
		cout<<diff<<endl;
	}
	return 0;
}
