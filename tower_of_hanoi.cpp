#include<stdio.h>

int tower_of_hanoi(int disks, char src, char aux, char dest){
	
	static int cnt = 0;
	if(disks == 0){
		return 0;
	}
	
	tower_of_hanoi(disks-1, src, dest, aux);
	printf("\nMove %d from %c to %c",disks,src,dest);
	cnt++;
	tower_of_hanoi(disks-1, aux,dest,src);
	
	return cnt;
}

int main(){
	printf("\nmoves : %d",tower_of_hanoi(3,'A','B','C'));
	return 0;
}
