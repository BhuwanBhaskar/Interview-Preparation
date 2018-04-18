#include<stdio.h>
#include<string.h>

void omit(char s[], char c) {
	
	s[0] = 'z';
	int i = 0;
	//printf("omited : %s",s);
	while(s[i] != '\0'){
		if(s[i] == c){
			
			int j = i+1;
			while(s[j] != '\0'){
				//printf("char : %c and %c",s[j-1],s[j]);
				s[j-1] = s[j];
				j++;
			}
			s[j] = '\0';
		}
		i++;
	}
	printf("omited : %s",s);
}
int main(){
	
	char *s = "abcbcdefc\0";
	omit(s,'c');
	//printf()
	return 0;
}
