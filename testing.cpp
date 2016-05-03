#include<stdio.h>

int main(){
	int a = 5;
	int *ptr = &a;
	*ptr = 7;
	printf("%d",*ptr);
}
