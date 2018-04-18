#include<stdio.h>

int main(){
	int max_topic = 0, max_cnt = 0,cnt = 0,topic = 0;
	int p,t;
	scanf("%d%d",&p,&t);
	int mat[p][t];
	for(int i = 0; i < p; i++){
		for(int j = 0; j < t; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	
	for(int i = 0; i < p; i++){
		printf("\n");
		for(int j = 0; j < t; j++){
			printf("%d",mat[i][j]);
		}
	}
	for(int i = 0; i < p; i++){
		for(int j = i+1; j < p; j++){
			topic = 0;
			for(int k = 0; k < t; k++){
				if(mat[j][k] || mat[i][k]){
					topic++;
				}
				
				if(max_topic == topic){
				printf("\nperson : %d and %d",i,j);
				max_cnt++;
			}
			if(max_topic < topic){
				max_topic = topic;
				printf("\n****person : %d and %d",i,j);
				max_cnt = 1;
			}
			}
		}
	}
	
	printf("\n%d and %d",max_topic,max_cnt);
	return 0;
}
