#include<stdio.h>
#include<limits.h>

int crossOverSum(int arr[], int low, int mid, int high){
	int left_sum = INT_MIN;
	int sum = 0;
	
	for(int i = mid; i >= low; i--){
		sum += arr[i];
		if(sum > left_sum)
			left_sum = sum;
	}
	
	int right_sum = INT_MIN;
	sum = 0;
	
	for(int i = mid+1; i <= high; i++){
		sum += arr[i];
		if(sum > right_sum)
			right_sum = sum;
	}
	
	return left_sum + right_sum;
}

//Cormen' Divide and Conquer Algorithm O(nlogn)
int maxSubArraySum(int arr[], int low, int high){
	
	int lsum = 0,rsum = 0, csum = 0;
	if(low < high){
		int mid = low + (high-low)/2;
		lsum = maxSubArraySum(arr,low,mid);
		rsum = maxSubArraySum(arr,mid+1,high);
		csum = crossOverSum(arr,low,mid,high);
		
		if(lsum>=rsum && lsum>=csum)
			return lsum;
		else if(rsum>=lsum && rsum>=csum)
			return rsum;
		else
			return csum;
	}else if(low == high){
		return arr[low];
	}
}

int max(int a, int b){
	return a > b ? a : b;
}
int iterative_maxSubArraySum(int arr[], int size){
	
	int csum = arr[0];
	int cmax = arr[0];
	
	for(int i = 1; i < size; i++){
		csum = max(csum+arr[i],arr[i]);
		cmax = max(cmax,csum);
	}
	return cmax;
}

int main(){
	
	int arr[] = {-2, -3, 4, -1, 2, -1, -5, -3};
	
	printf("\nLargest Sum : %d",maxSubArraySum(arr,0,sizeof(arr)/sizeof(arr[0]) - 1));
	printf("\nLargest Sum : %d",iterative_maxSubArraySum(arr,sizeof(arr)/sizeof(arr[0])));
	return 0;
}
