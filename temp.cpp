#include<stdio.h>

int main(){
	
	char *p1 = "abc",*p2;
	p2 = p1;
	p1 = "efgt";
	printf("%s and %s",p1,p2);
}
