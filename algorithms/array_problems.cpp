#include<stdio.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
	return a > b ? a : b;
}
int sumIt(int a[], int n){
	
	int temp = a[0];
	for(int i = 1; i < n; i++){
		temp += a[i];
	}
	return temp;
}

void printIt(int a[], int n){
	printf("\n");
	for(int i = 0; i < n; i++){
		printf(" %d ",a[i]);
	}
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Equilibrium index of an array is an index such that the 
//sum of elements at lower indexes is equal to the sum of elements at higher indexes.
int equilibriumIndex(int a[], int n){
	
	int sum = sumIt(a,n);
	int left_sum = 0;
	for(int i = 0; i < n; i++){
		sum -= a[i];
		if(left_sum == sum){
			return i;
		}
		left_sum += a[i];
	}
	return -1;
}

//Given an array of n elements which contains elements from 0 to n-1, 
//with any of these numbers appearing any number of times. 
//Find these repeating numbers in O(n) and using only constant memory space.
//does not handle if a[i] == 0 ..
void printDuplicates(int a[], int n){
	
	printf("\nDuplicates are : ");
	for(int i = 0; i < n; i++){
		
		if(a[abs(a[i])] >= 0){
			a[abs(a[i])] = -a[abs(a[i])];
		}else{
			printf(" %d ",abs(a[i]));
		}
	}
}

//Given an array arr[] of integers, 
//find out the difference between any two elements such that larger
// element appears after the smaller number in arr[].

int find_diff(int a[], int n){
	
	int max_diff = a[1]-a[0],min = a[0];
	
	for(int i = 1; i < n; i++){
		if(max_diff < a[i]-min){
			max_diff = a[i]-min;
		}
		if(min > a[i]){
			min = a[i];
		}
	}
	return max_diff;
}

//find first occurrence of key in sorted arrya a[]
// 'f' is for first occurrence and 'l' is for last occurrence otherwise return from mid
int binary_search(int a[], int n, int key, char ch = 'f'){
	
	int mid,low = 0, high = n-1, res = -1;
	while(low <= high){
		mid = low + (high-low)/2;
		if(a[mid] == key){
			res = mid;
			if(ch == 'f'){
				high = mid-1;
			}else if(ch == 'l'){
				low = mid+1;
			}else{
				return mid;
			}
		}
		else if(key < a[mid]){
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return res;
}

//majority elmt is te elmt which occurs in array more than n/2 times
bool isMajority(int a[], int n, int x){
	
	int ind = binary_search(a,n,x);
	if(ind != -1){
		return ind+n/2 < n && a[ind+n/2] == a[ind];
	}
	return false;
}

//Given an array of positive numbers, find the maximum sum of a subsequence with the constraint 
//that no 2 numbers in the sequence should be adjacent in the array.
// So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7)

int find_sum(int a[], int n){
	
	int incl = a[0],excl = 0,excl_new;
	for(int i = 1; i < n; i++){
		excl_new = incl > excl ? incl : excl;
		
		incl = excl + a[i];
		excl = excl_new;
	}
	return max(incl,excl);
}

//reverse array between beg and end inclusive
void reverse(int a[], int beg, int end){
	
	while(beg < end){
		swap(&a[beg],&a[end]);
		beg++;
		end--;
	}
}
//Left/right rotate an array by d elmt..d left rotation == n-d right rotation
void rotate(int a[], int n, int d){
	
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
}

int main(){
	
	{
		int arr[] = {-7, 1, 5, 2, -4, 3, 0};
  		int arr_size = sizeof(arr)/sizeof(arr[0]);
  		printf("First equilibrium index is %d\n", equilibriumIndex(arr, arr_size));
	}
	
	{
		int arr[] = {1, 2, 3, 1, 3, 6, 6};
  		int arr_size = sizeof(arr)/sizeof(arr[0]);
  		printDuplicates(arr, arr_size);
	}
	
	{
		int arr[] = {1, 2, 6, 80, 100};
  		int size = sizeof(arr)/sizeof(arr[0]);
  		printf("Maximum difference is %d",  find_diff(arr, size));
	}
	
	{
		int arr[] = {1, 2, 3, 3, 3, 3, 10};
    	int n = sizeof(arr)/sizeof(arr[0]);
    	int x = 3;
    	if (isMajority(arr, n, x))
        	printf("\n%d appears more than %d times in arr[]",
               x, n/2);
    	else
        	printf("\n%d does not appear more than %d times in arr[]",
               x, n/2);
	}
	
	{
		int arr[] = {5, 5, 10, 100, 10, 5};
  		printf("\n%d \n", find_sum(arr, 6));
	}
	
	{
		int arr[] = {1, 2, 3, 4, 5, 6, 7};
    	int n = sizeof(arr)/sizeof(arr[0]);
    	rotate(arr,n,2);
    	printIt(arr,n);
	}
	return 0;
}
