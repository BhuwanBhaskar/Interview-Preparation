#include<stdio.h>
#include<limits.h>

void printIt(int arr[], int size){
	printf("\n\n Printing Array : \n ");
	for(int i = 0; i < size; i++){
		printf("%d\t",arr[i]);
	}
}

void printItBw(int arr[], int beg, int end){
	printf("\n\n Printing array in between : %d and %d : \n ",beg,end);
	for(int i = beg; i <= end; i++){
		printf("%d\t",arr[i]);
	}
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void unknow_sort(int arr[], int size){
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < i; j++){
			 //take a[i] and compare it with all its previous elmts and find out correct position for it
			if(arr[i] < arr[j]){
				swap(&arr[i],&arr[j]);
			}
		}
	}
}

void bubble_sort(int arr[], int size){
	//swapped is used to prevent outer loop to run multiple times even if input is sorted 
	bool swapped = true;
	for(int i = 0; i < size && swapped; i++){
		swapped = false;
		for(int j = 0; j < size-1; j++){
			if(arr[j+1] < arr[j]){
				swap(&arr[j+1], &arr[j]);
				swapped = true;
			}
		}
		//printIt(arr,size);
	}
}

int findIndSmallest(int arr[], int beg, int end){
	int ind = beg;
	for(int i = beg+1; i < end; i++){
		if(arr[ind] > arr[i]){
			ind = i;
		}
	}
	return ind;
}

void selection_sort(int arr[], int size){
	
	for(int i = 0; i < size; i++){
		swap(&arr[i], &arr[findIndSmallest(arr, i, size)]);
	}
}

void insertion_sort(int arr[], int size){
	//take each elmt one by one and compare it to all elmts to left of it..then shift
	for(int i = 1; i < size; i++){
		int j = i-1;
		int key = arr[i];
		while(j >= 0 && arr[j] > key){
			//right shift elmts
			arr[j+1] = arr[j];
			j--;
		}
		//put key into correct pos
		arr[j+1] = key;
		//printIt(arr,size);
	}
}

void merge(int arr[], int beg, int middle, int end){
	
	int l = beg, m = middle+1;
	int merged[end-beg+1], k = 0;
	
	while(l <= middle && m <= end){
		
		if(arr[l] <= arr[m]){
			merged[k] = arr[l++];
		}else if(arr[l] > arr[m]){
			merged[k] = arr[m++];
		}
		k++;
	}
	
	while(l <= middle){
		merged[k++] = arr[l++];
	}
	
	while(m <= end){
		merged[k++] = arr[m++];
	}
	
	k = 0;
	for(int i = beg; i <= middle; i++){
		arr[i] = merged[k++];
	}
	for(int i = middle+1; i <= end; i++){
		arr[i] = merged[k++];
	}
}

void merge_sort(int arr[], int beg, int end){
	
	if(end > beg){
		int middle = beg + (end-beg)/2;
		merge_sort(arr, beg, middle);
		merge_sort(arr, middle+1, end);
		merge(arr, beg, middle, end);
	}
}

void merged_sort(int arr[], int size){
	merge_sort(arr, 0, size-1);
}

//it returns an index suh that all elmts left to the index are smaller and all items right to the index are greater
int partition(int arr[], int beg, int end){
	
	//take pivot as first elmt
	//we can randomize index selection (for further optimization we can take median of 3 randomly selected index)
	//int r = rand()%(end-beg+1);
	//swap(&arr[r+beg],&arr[beg]);
	
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

//removes recursion..but add its own stack (which is same)
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position in sorted array
        int p = partition( arr, l, h );
 
        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

void quick_sort_util(int arr[], int beg, int end){
	
	if(end <= beg){
		return;
	}
	int pivot = partition(arr, beg, end);
	quick_sort_util(arr, beg, pivot-1);
	quick_sort_util(arr, pivot+1, end);
}

//Tail recursion optimization in quick sort
//it will prevent stack overflow as same stack space will be used for iterative process so 
//no need of extra stack space for processing right subarray
//only in worst case (when input is already sorted) it will behave as normal quick sort algo..since
//first recusion will keep on consuming stack space
//but we can reduce stack space in worst case also ..by sorting smaller subaaray and doing iteration
//on larger subarray
void quick_sort_tail_recursion(int arr[], int beg, int end){
	
	while(beg < end){
		int pivot = partition(arr,beg,end);
		
		//first subarray is smaller so process it on stack
		if(pivot-beg < end-pivot){
			quick_sort_tail_recursion(arr,beg,pivot-1);
			beg = pivot + 1;
		}else{
			quick_sort_tail_recursion(arr,pivot+1,end);
			end = pivot-1;
		}
	}
}

void quick_sort_3way_util(int arr[], int beg, int end){
	
	if(end <= beg){
		return;
	}
	//Using Dijkastra' dutch flag problem solution
	//arr[ < pivot .........== pivot .........> pivot]
	//...low...............lt.......gt..............high
	
	int pivot = arr[beg];
	int lt = beg, gt = end, i = beg;
	
	while(i <= gt){
		
		//move all elmts greater than pivot in (gt....end]
		if(pivot < arr[i]){
			//we are not moving i becoz we are not sure if new elmt is less than pivot..so we will check it again
			//but gt should be decremented as we know that a[gt == i] > pivot
			swap(&arr[i], &arr[gt--]);
		}else if(arr[i] < pivot){
			//move all elmts less than pivot in [beg....lt)
			swap(&arr[i++],&arr[lt++]);
		}else{
			//all equal elmts are in [lt....gt]
			i++;
		}
	}
	
	quick_sort_3way_util(arr,beg,lt-1);
	quick_sort_3way_util(arr,gt+1,end);
	
}

void quick_sort(int arr[], int size){
	//quick_sort_util(arr, 0, size-1);
	
	//three way sorting
	//a[ < pivot ..........== pivot...........> pivot]
	//quick_sort_3way_util(arr,0,size-1);
	
	//Tail recursive quick_sort
	//quick_sort_tail_recursion(arr,0,size-1);
	
	quickSortIterative(arr,0,size-1);
}

void max_heapify(int arr[], int index, int length){
	int largest = index;
	int left = 2*index+1;
	int right = 2*index+2;
	if(left < length && arr[largest] < arr[left]){
		largest = left;
	}
	if(right < length && arr[largest] < arr[right]){
		largest = right;
	}
	
	if(largest != index){
		swap(&arr[largest],&arr[index]);
		max_heapify(arr,largest,length);
	}
}

void build_max_heap(int arr[], int size){
	
	for(int i = size/2; i >= 0; i--){
		max_heapify(arr,i,size);
	}
}

int extract_max(int arr[], int length){
	
	int max = arr[0];
	arr[0] = arr[length-1];
	length--;
	max_heapify(arr,0,length);
	
	return max;
}

int parentOf(int i){
	return (i-1)/2;
}

void heap_increase_key(int arr[], int index, int key){
	if(key < arr[index]){
		return ;
	}
	arr[index] = key;
	while(index > 0 && arr[parentOf(index)] < arr[index]){
		swap(&arr[parentOf(index)], &arr[index]);
		index = parentOf(index);
	}
}

void heap_insert(int arr[],int length,int key, int size){
	
	if(length >= size){
		printf("\nNo Memory Available !!!");
		return;
	}
	length++;
	arr[length-1] = INT_MIN;
	heap_increase_key(arr,length-1,key);
}

void __build_max_heap(int arr[],int size){
	int length = 0;
	for(int i = 1; i < size; i++){
		heap_insert(arr,length,arr[i],size);
		//printIt(arr,length);
		length++;
	}
}

void sort_nearly_sortedK(int arr[], int size, int k){
	
	//create a max heap of size k+1
	int length = k+1;
	int heap[k+1];
	for(int i = 0; i < length; i++){
		heap[i] = arr[i];
	}
	
	build_max_heap(heap,length);
	//printIt(heap,length);
	
	for(int i = k+1,ai = 0; ai < size; ai++,i++){
	
		if(i < size){
			arr[ai] = heap[0];
			heap[0] = arr[i];
			max_heapify(heap,0,length);
		}else{
			arr[ai] = extract_max(heap,length);
			length--;
		}
	}
}

void heap_sort(int arr[], int size){
	
	__build_max_heap(arr,size);
	printIt(arr,size);
	
	build_max_heap(arr,size);
	printIt(arr,size);
	
	printf("\nMax is : %d",extract_max(arr,size));
	printIt(arr,size);
	
	int length = size;
	for(int i = size-1; i > 0; i--){
		swap(&arr[0],&arr[i]);
		
		length--;
		max_heapify(arr,0,length);
	}
}
//Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] 
//such that sorting this subarray makes the whole array sorted.
void min_unsorted_subarray(int arr[], int size){
	
	int beg = 0, end = size-1;
	
	//find first elmt [from left] which is smaller than previous elmt
	while(arr[beg] < arr[beg+1]){
		beg++;
	}
	
	//find first elmt [from right] which is greater than previous elmt
	while(arr[end-1] < arr[end]){
		end--;
	}
	
	//find min and max in [beg....end]
	int min = arr[beg],max = arr[end];
	for(int i = beg; i <= end; i++){
		if(arr[i] < min){
			min = arr[i];
		}
		if(max < arr[i]){
			max = arr[i];
		}
	}
	printf("\nMin and max : %d and %d",min,max);
	beg = 0;
	while(arr[beg] < min){
		beg++;
	}
	end = size-1;
	while(max < arr[end]){
		end--;
	}
	
	printf("\nUnsorted subarray is : [%d.....%d]",beg,end);
	
	return;
}

//Sort a big array with many repetitions..
//we should use self balancing binary search tree ex AVL or red black (its struture should include count field also)
//complexity will be O(nlogm) m is no of distinct elmts


//COUNT sort
void count_sort(int a[], int n, int range){
	int count[range] = {0};
	int output[n] = {0};
	
	
	for(int i = 0; i < n; i++){
		count[a[i]]++;
	}
	
	//printIt(count,range);
	
	for(int i = 1; i < range; i++){
		count[i] += count[i-1];
	}
	//printIt(count,range);
	for(int i = n-1; i >= 0; i--){
		output[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = output[i];
	}
}

void count_sort_digits(int a[], int n, int exp){
	
	const int base = 10;
	int digits[10] = {0};
	int output[n] = {0};
	
	for(int i = 0; i < n; i++){
		digits[(a[i]/exp)%base]++;
	}
	
	for(int i = 1; i < 10; i++){
		digits[i] += digits[i-1];
	}
	
	for(int i = n-1; i >= 0; i--){
		output[digits[(a[i]/exp)%base]-1] = a[i];
		digits[(a[i]/exp)%base]--;
	}
	
	for(int i = 0; i < n; i++){
		a[i] = output[i];
	}
}

void radix_sort(int a[], int size){
	
	//get maximum no.
	int max = INT_MIN;
	for(int i = 0; i < size; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	
	//find no of digits in max and call count_sort for each digit position in form of 10^i
	for(int exp = 1; max/exp > 0; exp *= 10){
		count_sort_digits(a,size,exp);
	}
}

//sort an array in wave like form 
 //An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
 //ex {10, 5, 6, 3, 2, 20, 100, 80} ===> {10, 5, 6, 2, 20, 3, 100, 80} OR {20, 5, 10, 2, 80, 6, 100, 3}
 
 void sort_wave(int a[], int n){
 	//all elmts at even position will be greater than odd position adjacent to it
 	
 	for(int i = 0; i < n; i+=2){
 		
 		if(i != 0 && a[i] < a[i-1]){
 			swap(&a[i],&a[i-1]);
		 }
		 if(i != n-1 && a[i] < a[i+1]){
		 	swap(&a[i], &a[i+1]);
		 }
	 }
 }
 
int main(){
	
	int arr[] = {2,5,15,82,5,232,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	//printIt(arr,size);
	//bubble_sort(arr, size);
	//selection_sort(arr, size);
	//insertion_sort(arr,size);
	//merged_sort(arr, size);
	//quick_sort(arr, size);
	//printIt(arr, size);
	//heap_sort(arr,size);
	//printIt(arr,size);
	
	int nearly_sorted[] = {2, 6, 3, 56, 12, 8};
	int s = sizeof(nearly_sorted)/sizeof(nearly_sorted[0]);
	printIt(nearly_sorted,s);
	
	sort_nearly_sortedK(nearly_sorted,s,3);
	printIt(nearly_sorted,s);
	
	int unsorted_sub[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int u = sizeof(unsorted_sub)/sizeof(unsorted_sub[0]);
	
	min_unsorted_subarray(unsorted_sub,u);
	
	int a[] = {1, 4, 1, 2, 7, 5, 2};
	int sa = sizeof(a)/sizeof(a[0]);
	printIt(a,sa);
	int range = 10;
	count_sort(a,sa,range);
	printIt(a,sa);
	
	int radix[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int rs = sizeof(radix)/sizeof(radix[0]);
	printIt(radix,rs);
	
	radix_sort(radix,rs);
	printIt(radix,rs);
	
	int sortwave[] = {10, 5, 6, 3, 2, 20, 100, 80};
	int ss = sizeof(sortwave)/sizeof(sortwave[0]);
	printIt(sortwave,ss);
	
	sort_wave(sortwave,ss);
	printIt(sortwave,ss);
		
	bubble_sort(sortwave,ss);
	printIt(sortwave,ss);
	
	return 0;
}
