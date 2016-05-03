//Count number of inversions in array
//(i,j) is an inversion if i < j and a[i] > a[j]....it denotes how far or close an array is from being sorted

#include<stdio.h>
#include<limits.h>

int merge_inversions(int arr[], int low, int mid, int high){
	int no_fh = mid-low+1;
	int no_sh = high-mid;
	
	int first_half[no_fh+1];    //last two elmts are for sentinels (highest number possible)
	int second_half[no_sh+1];
	first_half[no_fh] = second_half[no_sh] = INT_MAX;
	
	for(int i = low,j = 0; i <= mid; i++, j++){
		first_half[j] = arr[i];
	}
	for(int i = mid+1, j = 0; i <= high; i++, j++){
		second_half[j] = arr[i];
	}
	
	int i,j,inversions,counted;
	i = j = inversions = counted = 0;
	for(int k = low; k <= high; k++){
		if(first_half[i] <= second_half[j]){
			arr[k] = first_half[i++];
		}else{
			inversions += no_fh-i; //remaining elmts
			arr[k] = second_half[j++];
		}
	}
	
	return inversions;
}

int count_inversions(int arr[], int low, int high){
	int inversions = 0;
	
	if(low < high){
		int mid = low + (high-low)/2;
		inversions += count_inversions(arr, low , mid);
		inversions += count_inversions(arr, mid+1, high);
		inversions += merge_inversions(arr, low, mid, high);
	}
	
	return inversions;
}

int countInversions(int arr[], int size){
	return count_inversions(arr, 0, size-1);
}

int main(){
	
	int arr[] = {1, 20, 6, 4, 5};
	
	printf("\nNumber of inversions : %d",countInversions(arr, sizeof(arr)/sizeof(arr[0])));
	
	return 0;
}
