#include<stdio.h>

double pow(double a, int b){
	double p;
	if(b == 0){
		return 1;
	}
	p = pow(a,b/2);
	if(b%2 == 0){
		return p*p;
	}else{
		if(b > 0){
			return a*p*p;
		}else{
			return (p*p)/a;
		}
	}
}

int main(){
	int b = -3;
	double a = 2;
	printf("\nPower of %lf^%d is %lf",a,b,pow(a,b));
	return 0;
}
