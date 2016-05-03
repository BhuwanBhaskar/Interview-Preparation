#include<stdio.h>
#include<limits.h>
//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
        	//printf("bef : %u", byte);
            byte = b[i] & (1<<j);
            //printf("\naft : %u", byte);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}

int main(){
	int i = 23;
    unsigned int ui = UINT_MAX;
    float f = 23.45f;
    //printBits(sizeof(i), &i);
    //printBits(sizeof(ui), &ui);
    //printBits(sizeof(f), &f);
    
    unsigned int x = -1; 
	int y = ~0; 
	int z = -1;
	char c = 125;
	printBits(sizeof(x), &x);
	printBits(sizeof(y), &y);
	printBits(sizeof(z), &z);
	printBits(sizeof(c), &c);
	c = c+10;
	printBits(sizeof(int), &c);
	printf("\n%d\n", c);
	printf("%u and %u  ",y,x);
	if (x == y) 
		printf("same"); 
	else
		printf("not same"); 

	return 0;
}
