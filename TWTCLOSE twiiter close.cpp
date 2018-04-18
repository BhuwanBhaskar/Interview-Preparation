#include<iostream>
#include<sstream>
 
using namespace std;
 
int string_to_int(string str)
{
	istringstream ss(str);
	int x;
	while(!ss.eof())
	{
		if(ss >> x)
			return x;
		ss.clear();
		ss.ignore();
	}
	return -1;
}
 
int main()
{
	int n,k;
	cin>>n>>k;
	cin.ignore();
	
	int clicks[k+1];
	string event;
	for(int i = 1; i <= k; i++)
	{
		getline(cin,event);
		char t = event[6];
		//cout<<event<<" "<<t<<endl;
		
		if(t >= '0' && t <= '9')
		{
			clicks[i] = string_to_int(event);
			if(clicks[i] == -1)
				return 1;
		}
		else
			clicks[i] = -1;
	}
	
	/*for(int i = 0; i < k; i++)
		cout<<clicks[i]<<" ";
	*/
	int state[n+1]; //0 denotes that twit is close and 1 => open
	int cnt = 0;
	for(int i = 0; i < n+1; i++)
		state[i] = 0;
			
	for(int i = 1; i <= k; i++)
	{
		if(clicks[i] == -1)
		{
			for(int i = 0; i < n+1; i++)
				state[i] = 0;
				cnt = 0;
			cout<<cnt<<endl;
		}
		else if(state[clicks[i]] == 0)
		{
			state[clicks[i]] = 1;
			cnt++;
			cout<<cnt<<endl;
		}
		else if(state[clicks[i]] == 1)
		{
			state[clicks[i]] = 0;
			cnt--;
			cout<<cnt<<endl;
		}
	}
    return 0;
}
