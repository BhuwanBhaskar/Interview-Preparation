//https://www.codechef.com/problems/CLEANUP

#include<iostream>
#include<cstring>
using namespace std;
#define N 1001
int jobs[N];
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	int t;
	cin>>t;
	
	for(int i = 0; i < t; i++){
		
		int n,m,ind;
		cin>>n>>m;
		
		memset(jobs,0,sizeof(jobs));
		
		for(int j = 1; j <= m; j++){
			cin>>ind;
			jobs[ind] = 1;
		}
		
		bool chef = true,blank_chef = true,blank_ass = true;
		for(int k = 1; k <= n; k++){
			if(chef && jobs[k] == 0){
				jobs[k] = 2;
				blank_chef = false;
				chef = false;
			}else if(jobs[k] == 0){
				jobs[k] = 3;
				chef = true;
				blank_ass = false;
			}
		}
		
		if(blank_chef){
			cout<<endl;
			cout<<endl;
		}else{
			for(int c = 1; c <= n; c++){
				if(jobs[c] == 2){
					cout<<c<<" ";
				}
			}
			if(blank_ass){
				cout<<endl;
			}else{
				cout<<endl;
				for(int a = 1; a <= n; a++){
					if(jobs[a] == 3){
					cout<<a<<" ";
					}
				}
			}
		}
		cout<<endl;
	}	
	return 0;
}
