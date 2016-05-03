#include<iostream>

using namespace std;

int main()
{
	int n,m,cnt = 0,extra,days;
	cin>>n>>m;
	
	extra = n/m;
	cnt = n;
	days = 0;
	
	while(days <= cnt)
	{
		if(days != 0 && days%m == 0)
		{
			cnt++;
			//cout<<" Buy socks on : "<<days<<endl;
		}
		days += m;	
	}
	
		
	cout<<cnt;
	return 0;
}
