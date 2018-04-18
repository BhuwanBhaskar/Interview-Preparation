#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//it returns an index suh that all elmts left to the index are smaller and all items right to the index are greater
int partition(int arr[], int beg, int end){
	
	//take pivot as first elmt
	//we can randomize index selection (for further optimization we can take median of 3 randomly selected index)
	//int p = rand()
	//swap(arr[beg],arr[p])
	
	int r = rand()%(end-beg+1);
	swap(&arr[r+beg],&arr[beg]);
	int p = arr[beg];
	int i = end+1;
	int j = beg;

	for(;;){
		
		while(arr[--i] > p){
			if(i <= beg){
				break;
			}
		}
		
		while(arr[++j] < p ){
			if(j >= end){
				break;
			}
		}
		
		if(i > j){
			swap(&arr[i],&arr[j]);
		}
		else{
			break;
		}
	}

	//if array is already sorted
	if(i == beg){
		return i;
	}
	swap(&arr[i], &arr[beg]);

	return i;
}


int kth_smallest_elmt(int arr[], int beg, int end, int k){
	
	if(k > 0 && k <= end-beg+1){
		
		int pivot = partition(arr,beg,end);
		
		//kth smallest will be at k-1 position...pivot-beg..becoz of relativ position
		if(pivot-beg == k-1){
			return arr[pivot];
		}else if(pivot-beg < k-1){
			//kth smallest elmt will be in right subarray since current position of pivot is smaller
			return kth_smallest_elmt(arr,pivot+1, end, (k-1)-(pivot-beg));	
		}else{
			return kth_smallest_elmt(arr,beg,pivot-1,k);
		}
	}
	return -1;
}

int main(){
	
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int k = 7;
	printf("\n%d smallest elmt is : %d",k,kth_smallest_elmt(arr,0,size-1,k));
	return 0;
}
