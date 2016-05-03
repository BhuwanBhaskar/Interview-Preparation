#include<stdio.h>
#include<conio.h>
#include<strings.h>
#include<stdlib.h>
#include<iostream>
int add(int a,int b){
	return a+b;
}
int sub(int a,int b){
	return a-b;
}
int mul(int a,int b){
	return a*b;
}
int rem(int a,int b){
	return a%b;
}

void printInt(void *a){
	printf(" %d ",*(int*)a);
}

void printChar(void *a){
	printf(" %c ",*(char*)a);
}

void printFloat(void *a){
	printf(" %f ",*(float*)a);
}

void printDouble(void *a){
	printf(" %lf ",*(double*)a);
}

void print(void *a, int n, void (*printType)(void *b)){
	
	//printf(" %d ",*(int*)((int*)a+i));
	printf("\n");
	for(int i = 0; i < n; i++){
		printType(((double*)a+i));
	}
}

void printDecToHexa(int val){
	
	int q = val/16;
	if(q){
		printDecToHexa(q);
	}
	putchar("0123456789ABCDEF"[val%16]);
}

void printDecToBinary(int val){
	
	int q = val/2;
	if(q){
		printDecToBinary(q);
	}
	putchar("01"[val%2]);
}

void printBinToAscii(int val){
	
	int q = val/10;
	if(q){
		printBinToAscii(q);
	}
	putchar(val%10+'0');
}

class Square
{
private:
    double m_length = 1.0; // m_length has a default value of 1.0
    double m_width = 2.2; // m_width has a default value of 1.0
 
public:
    Square(double len)
    {
    	m_length = len;
    // This constructor will use the default values above since they aren't overridden here
    }
 
    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
};

int main() {
	
	int (*pf[])(int,int) = {add,sub,mul,rem};
	
	printf("\nAdding : %d",pf[0](5,2));
	printf("\nsubbing : %d",pf[1](5,2));
	printf("\nmulling : %d",pf[2](5,2));
	printf("\nremming : %d",pf[3](5,2));
	
	double a[] = {1.00,2.00,3.00,4.00,5.00};
	int n = sizeof(a)/sizeof(a[0]);
	print(a,n,printDouble);
	
	printf("\nDecimal to Hexa :  ");
	int val = 4323;
	printDecToHexa(val);
	printf("\nDecimal to Binary :  ");
	printDecToBinary(val);
	printf("\nBinary to Ascii:  ");
	printBinToAscii('a');
	
	Square sq(5);
	sq.print();
	return 0;
}
