#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int capacity;
	int front,rear;
	int *queue;
};

void initialize(struct Queue **q, int capacity){
	*q = (struct Queue*)malloc(sizeof(struct Queue));
	(*q)->capacity = capacity;
	(*q)->front = (*q)->rear = -1;
	(*q)->queue = (int*) malloc(sizeof(int)*capacity);
}

void display(struct Queue *qu){
	printf("\nContents of Queue : ");
	for(int i = qu->front; i <= qu->rear; i++){
		printf("%d : %d\t",i,qu->queue[i]);
	}
}

void enqueue(struct Queue **qu, int item){
	
	if((*qu)->rear+1 == (*qu)->capacity){
		printf("\nQueue is full");
		return;
	}
	(*qu)->queue[++((*qu)->rear)] = item;
	if((*qu)->front == -1){
		(*qu)->front = 0;
	}
	
	display(*qu);
}

int dequeue(struct Queue **qu){
	
	if((*qu)->front == -1 || (*qu)->rear == -1){
		printf("\nQueue is empty");
		return -1;
	}
	
	//only one item in queue
	/*if((*qu)->rear-1 == (*qu)->front){
		int del = (*qu)->queue[(*qu)->rear];
	//	(*qu)->front = (*qu)->rear = -1;
		return del;
	}*/
	
	return (*qu)->queue[((*qu)->front)++];
}


int main(){
	struct Queue *qu = NULL;
	initialize(&qu, 10);
	
	for(int i = 0; i < 10; i++){
		if(i%2 == 0){
			enqueue(&qu, i);
		}
	}
	dequeue(&qu);
	dequeue(&qu);
	dequeue(&qu);
	dequeue(&qu);
	dequeue(&qu);
	for(int i = 0; i < 12; i++){
		if(i%2 == 0){
			enqueue(&qu, i);
		}
	}
	
	display(qu);
	
	return 0;
}
