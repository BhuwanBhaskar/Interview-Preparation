#include<stdio.h>

int operation(int a, int b, int *sum){
	*sum = a+b;
	return a-b;
}
int main(){
	int sum ;
	
	int x = operation(5,2,&sum);
	printf("sub : %d and sum : %d",x,sum);
	return 0;
}
