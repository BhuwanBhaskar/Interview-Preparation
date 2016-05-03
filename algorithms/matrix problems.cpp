#include<stdio.h>

#define ROW 4
#define COL 4

int mat[ROW][COL] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };

//O(n)
int searchSortedRowCol(int key){
	
	//start from rightmost and top elmt
	int i = 0,j = COL-1;
	
	//if key is grater than mat[i][j] then key does not exist
	
	while(i < ROW && j >= 0){
		
		if(mat[i][j] == key){
			printf("\nKey found at [%d][%d]",i,j);
			return i;
		}else if(mat[i][j] < key){
			i = i+1;
		}else{
			j = j-1;
		}
	}
	printf("\nKey does not exist");	
}

void printSpiral(){
	
	int dir = 0;
	//0 -> left to right; 1 -> top to bottom; 2 -> right to left; 3 -> bottom to top
	int i = 0;
	//dir0 and dir3 will always be incremented..dir1 and dir2 decremented
	//row is from dir0 till dir2 and col is from dir3 till dir1
	int dir0 = 0,dir1 = COL-1,dir2 = ROW-1,dir3 = 0;
	
	while(dir2 >= dir0 && dir3 <= dir1){
		
		if(dir == 0){
			//print from left to right...then increment row to avoid printing a[i][j] twice
			for(int k = dir0; k <= dir1; k++){
				printf("%d ",mat[dir0][k]);
			}
			dir0 = dir0+1;
		}else if(dir == 1){
			//print from top to bottom..decrement col j 
			for(int k = dir0; k <= dir2; k++){
				printf("%d ",mat[k][dir1]);
			}
			dir1--;
		}else if(dir == 2){
			//print from right to left
			for(int k = dir1; k >= dir3; k--){
				printf("%d ",mat[dir2][k]);
			}
			dir2--;
		}else{
			for(int k = dir2; k >= dir0; k--){
				printf("%d ",mat[k][dir3]);
			}
			dir3++;
		}
		dir = (dir+1)%4;
	}
}

//Given a boolean matrix mat[M][N] of size M X N,
// modify it such that if a matrix cell mat[i][j] is 1
// (or true) then make all the cells of ith row and jth column as 1.
void booleanIJ(int mat[][4], int m, int n){
	
	int setRow = 0, setCol = 0;
	
	//check if first row has 1
	for(int i = 0; i < n; i++){
		if(mat[0][i] == 1){
			setRow = 1;
			break;
		}
	}
	
	for(int j = 0; j < m; j++){
		if(mat[j][0] == 1){
			setCol = 1;
			break;
		}
	}
	
	printf("\nsetCol : %d and setRow : %d",setCol,setRow);
	
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(mat[i][j] == 1){
				mat[0][j] = 1;
				mat[i][0] = 1;
			}
		}
	}
	
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(mat[i][0] == 1 || mat[0][j] == 1){
				mat[i][j] = 1;
			}
		}
	}
	
	if(setRow){
		for(int i = 0; i < m; i++){
			mat[0][i] = 1;
		}
	}
	
	if(setCol){
		for(int i = 0; i < m; i++){
			mat[i][0] = 1;
		}
	}
}

int main(){
	//searchSortedRowCol(34);
	
	printSpiral();
	
	{
		int mat[][4] = { {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    	};
    	
    	booleanIJ(mat,3,4);
    	
    	printf("\n\n");
    	int i, j;
    	for (i = 0; i < 3; i++)
    	{
        	for (j = 0; j < 4; j++)
        	{
            	printf("%d ", mat[i][j]);
        	}
        	printf("\n");
    	}
	}
	return 0;
}
