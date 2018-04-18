#include<stdio.h>
#include<strings.h>
#include<limits.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

int find_max(int a[], int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

void printArray(int a[], int n){
	for(int i = 0; i < n; i++){
		printf(" %d ",a[i]);
	}
}

void setArray(int a[], int n, int x){
	for(int i = 0; i < n; i++){
		a[i] = x;
	}
}
//The longest Increasing Subsequence (LIS) problem is to find the length of the longest 
//subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. 
//L(i) = { 1 + Max ( L(j) ) } where j < i and arr[j] < arr[i] and if there is no such j then L(i) = 1
//O(n^2)
int longest_increasing_subsequence(int a[], int n){
	
	int sol[n];
	setArray(sol,n,1);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && sol[i] < sol[j]+1){
				sol[i] = sol[j]+1;
			}
		}
	}
	
	return find_max(sol,n);
}

//Given two sequences, find the length of longest subsequence present in both of them.
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
//If last characters of both sequences match (or X[m-1] == Y[n-1]) then
//L(X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2], Y[0..n-2])
//If last characters of both sequences do not match (or X[m-1] != Y[n-1]) then
//L(X[0..m-1], Y[0..n-1]) = MAX ( L(X[0..m-2], Y[0..n-1]), L(X[0..m-1], Y[0..n-2])
//O(n^2)

int longest_common_subs(char *s1, int m, char *s2, int n){
	
	int sol[m+1][n+1];
	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0){
				sol[i][j] = 0;
			}else if(s1[i-1] == s2[j-1]){
				sol[i][j] = 1 + sol[i-1][j-1];
			}else{
				sol[i][j] = max(sol[i][j-1],sol[i-1][j]);
			}
		}
	}	
	return sol[m][n];
}

//Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that 
//returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix 
//represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path 
//(including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell

//minCost(m, n) = min (minCost(m-1, n-1), minCost(m-1, n), minCost(m, n-1)) + cost[m][n]
//O(mn)

int min_cost(int cost[][5], int m, int n){
	
	int sol[m+1][n+1];
	
	sol[0][0] = cost[0][0];
	for(int i = 1; i <= n; i++){
		sol[i][0] = cost[i][0] + sol[i-1][0];
	}
	for(int i = 1; i <= n; i++){
		sol[0][i] = cost[0][i] + sol[0][i-1];
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			sol[i][j] = min(sol[i-1][j-1], min(sol[i-1][j],sol[i][j-1])) + cost[i][j];
		}
	}
	return sol[m][n];
}

//Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} 
//valued coins, how many ways can we make the change? The order of coins doesn’t matter.
//divide soln in two sets..sol contains coin sm and sol don't contain coin sm
//NOTE : this is not min coin change problem (in which we have to find minimum change of coins ex
//coins[] = {1,2,5} and amount = 11 then min coin change => 3 (5+5+1) but coin_change => 11 (all possible change of coins)
int coin_change(int coins[], int n, int money){
	
	int sol[money+1] = {0};
	sol[0] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = coins[i]; j <= money; j++){
			sol[j] += sol[j-coins[i]];
		}
	}
	return sol[money];
}

//Given weights and values of n items, put these items in a knapsack of capacity W 
//to get the maximum total value in the knapsack. In other words, given two integer
// arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated
// with n items respectively. Also given an integer W which represents knapsack capacity,
// find out the maximum value subset of val[] such that sum of the weights of this subset
// is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property)

//Sol : Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).
//OR Maximum value obtained by n-1 items and W weight (excluding nth item).

int knapsack(int wt[], int weight, int val[], int n){
	
	int sol[n+1][weight+1];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j<= weight; j++){
			if(i == 0 || j == 0){
				sol[i][j] = 0;
			}else if(wt[i-1] <= j){
				sol[i][j] = max(val[i-1] + sol[i-1][j-wt[i-1]], sol[i-1][j]);
			}else{
				sol[i][j] = sol[i-1][j];
			}
		}
	}
	return sol[n][weight];
}

//Find longest palindromic subsequence in string
int longest_palindromic_subs(char *str){
	
	int n = strlen(str);
	char string[n+1];
	strcpy(string,str);
	//strrev(str);
	printf("\n%s and %s",string,str);
	return longest_common_subs(string,n,str,n);
}

//Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
// Determine the maximum value obtainable by cutting up the rod and selling the pieces.
//Similar to coin change problem

int cut_rod(int price[], int n){
	
	int sol[n+1] = {0};
	
	for(int i = 1; i <= n; i++){
		
		int maxi = INT_MIN;
		for(int j = 0; j < i; j++){
			maxi = max(price[j]+sol[i-j-1], maxi);
		}
		sol[i] = maxi;
	}
	return sol[n];
}

//Given an array of n positive integers. Write a program to find the sum of maximum sum 
//subsequence of the given array such that the intgers in the subsequence are sorted in increasing order. 
//For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)
//same as LIS

int max_increasing_subs(int a[], int n){
	
	int sol[n+1];
	for(int i = 0; i < n; i++){
		sol[i] = a[i];
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(a[j] < a[i] && sol[i] < sol[j] + a[i]){
				sol[i] = sol[j] + a[i];
			}
		}
	}	
	return find_max(sol,n);
}

//Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called 
//Bitonic if it is first increasing, then decreasing. Write a function that takes an array as 
//argument and returns the length of the longest bitonic subsequence.
//A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty.
// Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.

int bitonic_subs(int a[], int n){
	
	//Find LIS
	//LDS (longest decreasing subs)
	//return max(lis[i],lds[i]-1);
	
	int sol_lis[n];
	setArray(sol_lis,n,1);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] < a[i] && sol_lis[i] < sol_lis[j]+1){
				sol_lis[i] = sol_lis[j]+1;
			}
		}
	}

	int sol_lds[n];
	setArray(sol_lds,n,1);
	for(int i = n-2; i >= 0; i--){
		for(int j = n-1; j > i; j--){
			if(a[j] < a[i] && sol_lds[i] < sol_lds[j]+1){
				sol_lds[i] = sol_lds[j]+1;
			}
		}
	}
	
	int maxi = INT_MIN;
	for(int i = 0; i < n; i++){
		maxi = max(maxi,sol_lds[i]+sol_lis[i]-1);
	}
	return maxi;
}

//Given a string, a partitioning of the string is a palindrome partitioning if 
//every substring of the partition is a palindrome. 
//For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
//Determine the fewest cuts needed for palindrome partitioning of a given string. 
//For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

int min_pal_partition(char str[]){
	
	int n = strlen(str);
	bool isPalindrome[n][n];
	
	//strings of 1 length are palindrome..and if strating char == ending char then palindrome
	for(int i = 0; i < n; i++){
		isPalindrome[i][i] = true;
	}
	for(int length = 2; length <= n; length++){
		for(int i = 0; i < n-length+1; i++){
			int j = length+i-1; //ending char
			
			if(length == 2){
				isPalindrome[i][j] = str[i] == str[j];
			}else{
				isPalindrome[i][j] = (str[i] == str[j]) && isPalindrome[i+1][j-1];
			}
		}
	}
	
	int cuts[n];
	for(int i = 0; i < n; i++){
		if(isPalindrome[0][i]){
			cuts[i] = 0;
		}else{
			cuts[i] = INT_MAX;
			for(int j = 0; j < i; j++){
				if(isPalindrome[j+1][i] && cuts[i] > cuts[j]+1){
					cuts[i] = cuts[j]+1;
				}
			}
		}
	}
	return cuts[n-1];
}

//Given an array of integers where each element represents the max number of steps 
//that can be made forward from that element. Write a function to return the minimum 
//number of jumps to reach the end of the array 
//(starting from the first element). If an element is 0, then cannot move through that element.

int min_jumps(int a[], int n){
	
	if(a[0] == 0 || n == 0){
		return -1;
	}
	
	int sol[n] = {0};
	for(int i = 1; i < n; i++){
		sol[i] = INT_MAX;
		for(int j = 0; j < i; j++){
			//check whether i is reachale from j or not...
			if(sol[j] != INT_MAX && i <= j+a[j]){
				//jump from a[j] to a[i]..so sol[j] +1
				sol[i] = min(sol[i],sol[j]+1);
				break;
			}
		}
	}
	return sol[n-1];
}

//Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
//1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
//shows the first 11 ugly numbers. By convention, 1 is included
int find_nth_ugly(int n){
	
	int ugly[n];
	ugly[0] = 1;
	int m2 = 2,m3 = 3,m5 = 5,i2 = 0,i3 = 0,i5 = 0,next_ugly = 1;
	for(int i = 1; i < n; i++){
	
		next_ugly = min(m2,min(m3,m5));
		ugly[i] = next_ugly;
		if(next_ugly == m2){
			i2++;
			m2 = ugly[i2]*2;
		}
		if(next_ugly == m3){
			i3++;
			m3 = ugly[i3]*3;
		}
		if(next_ugly == m5){
			i5++;
			m5 = ugly[i5]*5;
		}
	}
	
	//printf("\nUgly array : ");
	//printArray(ugly,n);
	return next_ugly;
}

//Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

void print_max_square(int matrix[][5], int m, int n){
	
	int sol[m][n];
	
	for(int i = 0; i < m; i++){
		sol[0][i] = matrix[0][i];
	}
	for(int i = 0; i < n; i++){
		sol[i][0] = matrix[i][0];
	}
	
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(matrix[i][j]){
				sol[i][j] = min(sol[i-1][j],min(sol[i][j-1],sol[i-1][j-1]))+1;
			}else{
				sol[i][j] = 0;
			}
		}
	}
	
	//find max in sol[][]
	int max = sol[0][0],maxi,maxj;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(max < sol[i][j]){
				max = sol[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}
	
	//print submatrix
	printf("\nMaximum Sub Matrix with all ones : ");
	for(int i = maxi; i > maxi-max; i--){
		printf("\n");
		for(int j = maxj; j > maxj-max; j--){
			printf(" %d ",matrix[i][j]);
		}
	}
}

//Given a string, find the longest substring which is palindrome. 
//For example, if the given string is “forgeeksskeegfor”, the output should be “geeksskeeg”.

int print_longest_pal(char str[]){
	
	int n = strlen(str);
	bool sol[n][n];
	int max_len = 1,st = 0;
	
	//string of 1 length
	for(int i = 0; i < n; i++){
		sol[i][i] = true;
	}
	//string of length 2
	for(int i = 0; i < n-1; i++){
		if(str[i] == str[i+1]){
			st = i;
			max_len = 2;
			sol[i][i+1] = true;
		}
	}
	
	//string of length more than 3
	for(int len = 3; len <= n; len++){
		for(int i = 0; i < n-len+1; i++){
			int j = i+len-1;
			
			if(str[i] == str[j] && sol[i+1][j-1]){
				sol[i][j] = true;
				if(max_len < len){
					max_len = len;
					st = i;
				}
			}else{
				sol[i][j] = false;
			}
		}
	}
	
	char result[max_len+1];
	strncpy(result,str+st,max_len);
	result[max_len] = '\0';
	printf("\nLongest Palindrome : %s",result);
	
	return max_len;
}

int main(){
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  	int n = sizeof(arr)/sizeof(arr[0]);
  	printf("Length of LIS is %d\n", longest_increasing_subsequence( arr, n ) );
  	
  	{
  		char X[] = "AGGTAB";
  		char Y[] = "GXTXAYB";
  
  		int m = strlen(X);
  		int n = strlen(Y);
  
  		printf("Length of LCS is %d\n", longest_common_subs( X,m, Y, n) );
	}
	
	{
		int cost[5][5] = { {1, 2, 3},
                      	 {4, 8, 2},
                      	 {1, 5, 3} };
   		printf("\n%d ", min_cost(cost, 2, 2));
	}
	
	{
		int arr[] = {1, 2, 5};
    	int m = sizeof(arr)/sizeof(arr[0]);
    	int n = 11;
    	printf("\ncoin change : %d ", coin_change(arr, m, n));
	}
	
	{
		int val[] = {60, 100, 120};
    	int wt[] = {10, 20, 30};
    	int  W = 50;
    	int n = sizeof(val)/sizeof(val[0]);
    	printf("\n%d", knapsack(wt, W, val, n));
	}
	
	{
		char seq[] = "GEEKS FOR GEEKS";
    	printf ("\nThe lnegth of the LPS is %d", longest_palindromic_subs(seq));
	}
	
	{
		int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    	int size = sizeof(arr)/sizeof(arr[0]);
    	printf("\nMaximum Obtainable Value is %d\n", cut_rod(arr, size));
	}
	
	{
		int arr[] = {1, 101, 2, 3, 100, 4, 5};
    	int n = sizeof(arr)/sizeof(arr[0]);
    	printf("\nSum of maximum sum increasing subsequence is %d\n",
           max_increasing_subs( arr, n ) );
	}
	
	{
		int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
  		int n = sizeof(arr)/sizeof(arr[0]);
  		printf("\nLength of LBS is %d\n", bitonic_subs( arr, n ) );
	}
	
	{
		char str[] = "ababbbabbababa";
   		printf("Min cuts needed for Palindrome Partitioning is %d",
           min_pal_partition(str));
	}
	
	{
		int arr[] = {1, 3, 6, 1, 0, 9};
    	int size = sizeof(arr)/sizeof(int);
    	printf("\nMinimum number of jumps to reach end is %d ", min_jumps(arr,size));
	}
	{
		int n = 150;
		printf("\n%d ugly number is : %d",n,find_nth_ugly(n));
	}
	
	{
		int M[6][5] =  {{0, 1, 1, 0, 1}, 
        	           {1, 1, 0, 1, 0}, 
            	       {0, 1, 1, 1, 0},
                	   {1, 1, 1, 1, 0},
                   	   {1, 1, 1, 1, 1},
                	   {0, 0, 0, 0, 0}};
                
  	    print_max_square(M,6,5);
	}
	
	{
		char str[] = "forgeeksskeegfor";
    	printf("\nLength is: %d\n", print_longest_pal( str ) );
	}
	return 0;
}
