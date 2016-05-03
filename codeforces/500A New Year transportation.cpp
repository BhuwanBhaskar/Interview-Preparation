#include<stdio.h>

int main(){
	
	int n,t;
	scanf("%d%d",&n,&t);
	
	int ai;
	int src = 1;
	int prev = 1,next;
	//go from src to t;
	for(int i = 1; i < n; i++){
		scanf("%d",&ai);
		
		if(prev == i){
			prev = i+ai;
			if(prev == t){
				printf("YES");
				return 0;
			}
		}
	}
	
	printf("NO");
	return 0;
}
