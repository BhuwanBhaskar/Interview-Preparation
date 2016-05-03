#include<iostream>

using namespace std;

int lcs(string str1 , string str2)
{
	int sol[str1.length()+1][str2.length()+1];
	
	for(int i = 0; i < str1.length()+1; i++)
	{
		for(int j = 0; j < str2.length()+1; j++)
		{
			if(i == 0 || j == 0)
					 sol[i][j] = 0;		
			else if (str1[i] == str2[j])
		    sol[i][j] = 1 + sol[i-1][j-1];
			else 
		    sol[i][j] = sol[i][j-1] > sol[i-1][j] ? sol[i][j-1] : sol[i-1][j];
		}
	}
	
	return sol[str1.length()][str2.length()];
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	
	cout << lcs(str1,str2)<<endl;
	
	return 0;
}
