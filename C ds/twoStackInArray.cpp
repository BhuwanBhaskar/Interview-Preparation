#include<stdio.h>
#define MAX 5

int arr[MAX];
int topf = -1;
int topr = MAX;

void push(char side, int item){
	
	//push in front side " first half "
	if(side == 'f'){
		if(topf+1 == topr){
			printf("\nFirst half overflow");
			return;
		}else{
			arr[++topf] = item;
		}
	}
	else if(side == 'r'){
		if(topr-1 == topf){
			printf("\nSecond half overflow");
			return;
		}else{
			arr[--topr] = item;
		}
	}else{
		return;
	}
}

int pop(char side){
	if(side == 'f'){
		if(topf == -1){
			printf("\nFirst half underflow");
			return -1;
		}else{
			return arr[topf--];
		}
	}else if(side == 'r'){
		if(topr == MAX){
			printf("\nSecond half underflow");
			return -2;
		}else{
			return arr[topr++];
		}
	}
}

int peek(char side){
	if(side == 'f'){
		if(topf == -1){
			printf("\nFirst half underflow");
			return -1;
		}else{
			return arr[topf];
		}
	}else if(side == 'r'){
		if(topr == MAX){
			printf("\nSecond half underflow");
			return -2;
		}else{
			return arr[topr];
		}
	}
}

bool isFull(){
	return topf == topr-1;
}

void display(){
	printf("\nFront stack : ");
	for(int i = 0; i <= topf; i++){
		printf("%d ",arr[i]);
	}
	
	printf("\nRear Stack : ");
	for(int i = MAX-1; i >= topr; i--){
		printf("%d ",arr[i]);
	}
}

int main(){
	
	push('f', 10);
	push('r', 15);
	push('f', 20);
	push('r', 25);
	push('f', 30);
	pop('r');
	push('r', 35);
	
	display();
	
	return 0;
}
