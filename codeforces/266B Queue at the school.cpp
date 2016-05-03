#include<iostream>
#include<algorithm>
using namespace std;

/*

22 7
GBGGBGGGGGBBBGGBGBGBBB
Output
GGGGGGGGBBGGGGBBBBBBBB
Answer
GGGGGGGGBGGBGGBBBBBBBB

*/
int main()
{
	int n,t;
	cin>>n>>t;
	string queue;
	cin>>queue;
	int moved[queue.length()] = {0};
	
	int nb = count(queue.begin(),queue.end(),'B');
	int i = queue.find_first_of('B');
	//int j = queue.find_first_of('B');
	int time = 1;
	int b = 1;
/*	while(b <= nb && t >= 1)
	{t--;
		//take current boy and mpve him to his left
		int pos = i + 1;
		int j = pos;
		if(pos > n)
			j = n;
			
		while(i < j)
		{
			if(queue[j] == 'G' && moved[j] == 0)
				break;
			j--;
		}
		swap(queue[i],queue[j]);
		moved[j] = 1;
		//find out next boy in string starting from 0..i
		i = i+1;
		while(i < queue.length())
		{
			if(moved[i] == 1 || queue[i] == 'G')
				i++;
			else if(moved[i] == 0 && queue[i] == 'B')
				break;
		}
		cout<<queue<<endl;
		//i = queue.find_first_of('B',i+1);
		b++;
	}*/
	
	for(int i = 1; i <= t; i++)
	{
		int moved[n] = {0};
		for(int j = 0; j < n; j+=1)
		{
			//let us swap boy and girl...ex BG => GB
			if(queue[j] == 'B' && queue[j+1] == 'G' && moved[j] == 0)
			{
				swap(queue[j],queue[j+1]);
				moved[j+1] = 1;
			}
		}
		//cout<<queue<<endl;
	}
	cout<<queue;
	return 0;
}
