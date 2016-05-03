#include<iostream>

using namespace std;

void composite_sieve(long n)
{
	bool isComposite[n+1] = {0};
	
	for(long i = 2; i*i <= n; i++)
	{
		if(!isComposite[i])
		{
			for(long j = i*i; j <= n; j += i)
			{
				isComposite[j] = 1;
			}
		}
	}
	long csum = 0;
	for(long i = 4,j = n-4; i < n && j > 4; )
	{
		csum = 0;
		if(isComposite[i])
		{
			if(isComposite[j])
				csum = i+j;
			else if(!isComposite[j])
				j--;
		}
		else if(isComposite[j])
		{
			if(isComposite[i])
				csum = i+j;
			else if(!isComposite[i])
				i++;
		}
		else if(!isComposite[i] && !isComposite[j])
		{
			i++;
			j--;
		}
		
		if(csum == n)
		{
			cout<<i <<" "<< j;
			return ;
		}
		else if(csum != 0 && csum < n)
			i++;
		else if(csum != 0 && csum > n)
			j--;
	}
	return;
}

int main()
{
	long comp;
	cin>>comp;
	
	if(comp%2)
		cout<<comp-9 <<" "<<9;
	else
		cout<<comp-8<<" "<<8;
		
	//composite_sieve(comp);
	
	return 0;
}
