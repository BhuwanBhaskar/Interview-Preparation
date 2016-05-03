#include<stdio.h>
#include<limits.h>
void find_min(int arr[], int n, int *min, int *smin){
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		//Won't work..since min was assigned before smin came
		/*if(arr[i] < *min){
			*smin = *min;
			*min = arr[i];
		}*/
		
		if(arr[i] < *smin){
			cnt++;
			if(arr[i] < *min){
				cnt++;
				
				*smin = *min;
				*min = arr[i];
			}
			else{
				*smin = arr[i];
			}
		}
	}
	
	printf("\nTotal Number of comparisons :  %d",cnt);
}

int main(){
	
	int min = INT_MAX,smin = INT_MAX;
	int arr[] = {5,3,4,1,7,6,8,2,9,10,31,-5,80,0,34,-10};
	int s = sizeof(arr)/sizeof(arr[0]);
	
	find_min(arr,s,&min,&smin);
	
	printf("\nMin is %d and Second Min is %d",min,smin);
}
