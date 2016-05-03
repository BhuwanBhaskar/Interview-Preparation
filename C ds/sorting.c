#include<stdio.h>

void printIt(int arr[], int size){
	printf("\n Printing Array : ");
	for(int i = 0; i < size; i++){
		printf("%d\t",arr[i]);
	}
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int arr[], int size){
	
	for(int i = 0; i < size; i++){
		for(int j = 1; j < i; j++){
			if(a[i] < a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}
int main(){
	
	int arr[6] = {5,0,7,-2,10,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, size);
	
	printIt(arr, size);
	return 0;
}
