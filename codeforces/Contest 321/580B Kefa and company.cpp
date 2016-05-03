#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits>
using namespace std;

struct Friend
{
    long amount,factor;
};

int myComp(struct Friend f1, struct Friend f2)
{
    return f1.amount < f2.amount;
}

//we need to search for first occurrence of key or a value just grater than key
long bs_left(struct Friend friends[], long n, long key)
{
	long left = 0, right = n-1;
	long middle;
	
	while(left <= right)
	{
		middle = left + (right-left)/2;
		if(friends[left].amount == key)     //first occurrence of key
			return left;  
		else if(key <= friends[middle].amount)
			right = middle-1;
		else
			left = middle+1;
	}
			
	if(key <= friends[left].amount)
		return left;
	else
		return right;
}

//we have to search for last occurrence of key or a value just smaller than key
long bs_right(struct Friend friends[], long n, long key)
{
	long left = 0, right = n-1;
	long middle ;
	
	while(left <= right)
	{
		middle = left + (right-left)/2;
		//let us find last occurrence of number
		if(key == friends[right].amount)
			return right;
		else if(key < friends[middle].amount)
			right = middle-1;
		else if(key >= friends[middle].amount)
			left = middle+1;
	}
	
	if(key >= friends[right].amount )
		return right;
	else
		return left;
}

int main()
{
    long n,d;
    cin>>n>>d;

    struct Friend friends[n];
    for(long i = 0; i < n; i++)
    {
    	cin>>friends[i].amount;
		cin>>friends[i].factor;
	}
    
    sort(friends,friends+n,myComp);
    
    unsigned long long psum[n];
    psum[0] = friends[0].factor;
    for(int i = 1; i <= n-1; i++)
		psum[i] = psum[i-1] + friends[i].factor;
		
    unsigned long long maxf = 0;
    for(long i = 0; i <= n-1; i++)
    { 
    	long left_ind,right_ind;
    	long left_key = friends[i].amount-d+1;
    	long right_key = friends[i].amount+d-1;
    	
    	if(friends[i].amount+d-1 <= friends[0].amount)
    	{
    		left_ind = 0;
        	right_ind = bs_right(friends,n,right_key);
		}
        else if(friends[n-1].amount <= friends[i].amount-d+1)
        {
        	right_ind = n-1;
        	left_ind = bs_left(friends,n,left_key);
		}
		else
		{
			left_ind = bs_left(friends,n,left_key);
        	right_ind = bs_right(friends,n,right_key);
		}
        
        //cout<<friends[i].amount-d+1<<" "<<left_ind<<" "<<friends[i].amount+d-1<<" "<<right_ind<<endl;
        
        unsigned long long isum = 0;
        unsigned long long rsum = 0;
        
        if(left_ind == 0 || i == 0)
        	isum = psum[i];
        else if(left_ind <= i)	
        	isum = psum[i] - psum[left_ind-1];
		
        if(right_ind == 0 || i == 0)
        	rsum = psum[right_ind];
        else if(i <= right_ind)
        	rsum = psum[right_ind] - psum[i-1];
	
        maxf = max(maxf,max(rsum,isum));
    }
    cout<<maxf;
    
    return 0;
}
