#include<stdio.h>
#include<limits.h>
int med(int a[], int n){
	
	if(n%2){
		return a[n/2];
	}else{
		return (a[n/2] + a[n/2-1])/2.0;
	}
}

int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a < b ? a : b;
}

//Both array have same no of elmts
int median_sorted(int a[], int b[], int n){
	
	if(n <= 0){
		return -1;
	}else if(n == 1){
		//one elmt case
		return (a[0] + b[0])/2;
	}else if(n == 2){
		//two elmts case
		return (max(a[0], b[0]) + min(a[1], b[1]))/2;
	}else{
		int ma = med(a,n);
		int mb = med(b,n);
		
		if(ma == mb){
			return ma;
		}
		//median lies in a[ma...] and b[...mb]
		else if(ma < mb){
			//if odd no of elmts
			if(n%2){
				return median_sorted(a+n/2, b,n-n/2);
			}else{
				return median_sorted(a+n/2-1,b, n-n/2+1);
			}
		}else{
			//median lies in a[...ma] and b[mb...]
			if(n%2){
				return median_sorted(a, b+n/2, n-n/2);
			}else{
				return median_sorted(a,b+n/2-1,n-n/2+1);
			}
		}
	}
}

//this case handles : if one array has only one elmt and other has more than or equal to one elmt
double median_sorted_base_one(int med, int a[], int n){
	
	if(n == 1){
		return (med + a[0])/2.0;
	}
	else if(n%2){
		int meda1 = a[n/2-1], meda2 = a[n/2], meda3 = a[n/2+1];
		if(med <= meda1){
			//med lies in a[0...med1..meda2..meda3....]
			return (meda1+meda2)/2.0;
		}else if(med <= meda3){
			//a[0.....meda1..meda2..med..meda3....]
			return (med+meda2)/2.0;
		}else //if(meda3 < med)
		{
			//a[0...mead1..meda2..meda3..med..]
			return (meda2+meda3)/2.0;
		}
	}else{
		int meda1 = a[n/2-1], meda2 = a[n/2];
		if(med <= meda1){
			//a[0....med..meda1..meda2...]
			return meda1;
		}else if(meda2 < med){
			//a[0..meda1..meda2..med..]
			return meda2;
		}else if(med <= meda2){
			//a[0...meda1..med..meda2..]
			return med;
		}
	}
}
//this halndles : only one array has two elmts and other array has more than 1 elmts
//b[0...meda1...meda2....]
double median_sorted_base_two(int meda1, int meda2, int b[], int n){
	
	//since we are mering two elmts to b[] so if n is odd then after adding two elmts to it..it will be odd :)
	if(n%2){
		printf("\nerror!!!");
		int medb1 = b[n/2-1],medb2 = b[n/2],medb3 = b[n/2+1];
		
		if(medb2 <= meda1){
			//b[0...medb1..medb2..meda1..meda2..medb3...]
			//b[0...medb1..medb2..meda1..medb3..meda2...]
			return min(meda1,medb3);
		}else if(meda2 <= medb2){
			//b[0....medb1..meda1..meda2..medb2....]
			//b[0...meda1..medb1..meda2..medb2.....]
			return max(meda2,medb1);
		}else if(meda1 < medb2 && medb2 < meda2){
			//b[0....meda1...medb2...meda2....]
			return medb2;
		}
	}else{
		printf("\nNOerror!!! : ");
		int medb1 = (n/2-2) >=0 ? b[n/2-2] : INT_MIN;
		int medb2 = b[n/2-1],medb3 = b[n/2];
		int medb4 = (n/2+1) <= n-1 ? b[n/2+1] : INT_MAX;
		
		if(meda2 <= medb2){
			//b[0...medb1..meda2..medb2...medb3...]
			printf(" %lf ",(medb2 + max(meda2,medb1))/2.0);
			return (medb2 + max(meda2,medb1))/2.0;
		}else if(meda1 <= medb2){
			//b[0...medb1..meda1..medb2...medb3...]
			printf(" %lf ",(medb2 + min(medb3,meda2))/2.0);
			return (medb2 + min(medb3,meda2))/2.0;
		}else if(medb3 <= meda1){
			//b[0....medb1..medb2..medb3..meda1..meda2...medb4]
			printf(" %lf ",(medb3 + min(medb4,meda1))/2.0);
			return (medb3 + min(medb4,meda1))/2.0;
		}else if(medb3 <= meda2){
			//b[0....medb1..medb2..meda1..medb3..meda2...]
			printf(" %lf ",(medb3 + max(meda1,medb2))/2.0);
			return (medb3 + max(meda1,medb2))/2.0;
		}else {
			printf(" medb1 : %d,medb2 : %d, meda1 : %d, meda2 : %d ",medb1,medb2,meda1,meda2);
			return (meda1+meda2)/2.0;
		}
	}
}

//both array have different no of elmts : a has m and b has n elmts
//assumtion is m < n
//if n == m then it is a special case we can call median_sorted() 
double median_sorted_general(int a[], int m, int b[], int n){
	
	//a is empty so return median of a
	if(m == 0){
		printf("\nm == 0");
		return (n%2 == 0) ? (b[n/2] + b[n/2-1])/2.0 : b[n/2];
	}else if(n == 0){
		printf("\nn== 0");
		return (m%2 == 0) ? (a[m/2] + a[m/2-1])/2.0 : a[m/2];
	}
	else if(m == 1){
		printf("\nm==1");
		return median_sorted_base_one(a[0],b,n);
	}else if(n == 1){
		printf("\nn==1");
		return median_sorted_base_one(b[0],a,m);
	}else if(m == 2){
		printf("\nm==2");
		return median_sorted_base_two(a[0],a[1],b,n);
	}else if(n == 2){
		printf("\nn== 2");
		return median_sorted_base_two(b[0],b[1],a,m);
	}else{
		printf("\nnon bese");
		int i = m/2, j = n/2, k;
		
		//we need to prune off equal no of elmts from both array
		//median will be in second half of a[] and first half of b[]
		if(a[i] <= b[j]){
			//if m%2 == 0 then a has even no of elmts so we should include one extra elmt before median of a[]
			//if its odd then lay off that elmt ..no need. n-j-1 is remaining elmt in b[] after median
			k = (m%2 == 0) ? min(i-1,n-j-1) : min(i,n-j-1);
			//select seond half of a and first half of b
			return median_sorted_general(a+k,m-k,b,n-k);
		}else{
			//median is in first half of a[] and in second half of b[]
			k = (n%2 == 0) ? min(m-i-1,j-1) : min(m-i-1,j);
			return median_sorted_general(a,m-k,b+k,n-k);
		}
	}
}

int main(){
	
	int a[] = {1, 5, 7, 10, 13};
	int b[] = {11, 15, 23, 30, 45};
	//1 5 7 10 11 13 15 23 30 45
	int s = sizeof(a)/sizeof(a[0]);
	printf("\nMedian of two sorted array is : %d",median_sorted(a,b,s));
	
	int a1[] = {1, 2, 4, 8, 9, 10};
	int b1[] = {3, 5, 6, 7};
	//1 2 3 4 5 6 7 8 9 10
	int m = sizeof(a1)/sizeof(a[0]);
	int n = sizeof(b1)/sizeof(a[0]);
	printf("\nMedian of two sorted array is : %f",median_sorted_general(a1,m,b1,n));
	printf("\nxvbnmMedian of two sorted array is : %f",median_sorted_general(b1,n,a1,m));
	return 0;
}
