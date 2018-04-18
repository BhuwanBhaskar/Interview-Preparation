// C program to sort an array of dates using Radix Sort
#include <stdio.h>
struct Date
{
	int d, m, y;
};

// Prototypes
void countSortDay(Date arr[], int n);
void countSortMonth(Date arr[], int n);
void countSortYear(Date arr[], int n);

// The main function that sorts array of dates
// using Radix Sort
void radixSortDates(Date arr[], int n)
{
// First sort by day
countSortDay(arr, n);

// Then by month
countSortMonth(arr, n);

// Finally by year
countSortYear(arr, n);
}

// A function to do counting sort of arr[] according to
// day
void countSortDay(struct Date d[], int n){
	struct Date output[n] ;
	int days[31] = {0};
	
	for(int i = 0; i < n; i++){
		days[d[i].d-1]++;
	}
	//Now days[] will have count of repeated days for each day..sine day begins with 1 so substracted it
	for(int i = 0; i < 31; i++){
		days[i] += days[i-1];
	}
	//Now days[i] will have how many days appear before and including days[i]
	
	for(int i = n-1; i >= 0; i--){
		//since we know how many days occur before ith day so
		output[days[d[i].d-1]-1] = d[i];
		//this is to avoid putting same day at same position..(avoids repetition)
		days[d[i].d-1]--;
	}
	
	for(int i = 0; i <n; i++){
		d[i] = output[i];
	}
	
}

// A function to do counting sort of arr[] according to
// month.
void countSortMonth(Date arr[], int n)
{
	Date output[n]; // output array
	int i, count[12] = {0};

	for (i = 0; i < n; i++)
		count[arr[i].m - 1]++;
	for (i = 1; i < 12; i++)
		count[i] += count[i - 1];
	for (i=n-1; i>=0; i--)
	{
		output[count[arr[i].m - 1] - 1] = arr[i];
		count[arr[i].m - 1]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// A function to do counting sort of arr[] according to
// year.
void countSortYear(Date arr[], int n)
{
	Date output[n]; // output array
	int i, count[1000] = {0};
	for (i = 0; i < n; i++)
		count[arr[i].y - 2000]++;
	for (i = 1; i < 1000; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[arr[i].y - 2000] - 1] = arr[i];
		count[arr[i].y - 2000]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// A utility function to print an array
void print(Date arr[], int n)
{
	int i;
	for (i=0; i<n; i++)
		printf("{%2d, %2d, %d}\n",
			arr[i].d, arr[i].m, arr[i].y);
}

// Driver program to test above functions
int main()
{
	Date arr[] = {{20, 1, 2014}, {25, 3, 2010},
				{3, 12, 2000}, {18, 11, 2001},
				{19, 4, 2015}, {9, 7, 2005}};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Input Dates\n");
	print(arr, n);
	radixSortDates(arr, n);
	printf("\nSorted Dates\n");
	print(arr, n);
	return 0;
}

