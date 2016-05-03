#include<stdio.h>

//[001010] ====> [010100]
unsigned int reverse_bits(unsigned int a){
	
	int n = 0;
	int cnt = 0;
	int temp = a;
	
	while(temp){
		cnt++;
		temp = temp<<1;
	}
	
	//printf("\nfirst loop : %d and %d and %d",temp,a,cnt);
	while(a != 0){
		//check least significant bit of a and copy it to n
		cnt--;
		if(a & 1){
			n |= (1<<cnt);
			//printf("\nBit set at %d. N is %u",cnt,n);
		}else{
			n &= ~(1<<cnt);
			//printf("\nBit reset at %d. N is %u",cnt,n);
		}
		a = (a >> 1);	
	}
	return n;	
}

unsigned reverse_bits2(int a){
	unsigned ans = 0;
	for(unsigned i = 1; i != 0; i <<= 1){
		
		ans <<= 1;
		if(a & 1){
			ans |= 1;
		}
		a >>= 1;
	}
	
	printf("\nAns : %u",ans);
	return ans;
}
int main(){
	unsigned int a = 25;
	printf("\na : %u , After Reversing bits  : %u",a,reverse_bits(a));
	reverse_bits2(a);
	return 0;
}
