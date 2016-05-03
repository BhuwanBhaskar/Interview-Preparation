#include<iostream>
#include<cmath>
using namespace std;
#define N 5
#define M 3    //middle coordinate of matrix (3,3)

int main()
{
	int mat[N][N];
	int locr,locc;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
		{
			cin>>mat[i][j];
			if(mat[i][j] == 1)
			{
				locr = i+1;  // to make counting start from 1
				locc = j+1;
			}
		}
	int row_mov = abs(locr-M);
	int col_mov = abs(locc-M);
	
	cout<<row_mov+col_mov;
	
	return 0;
}
