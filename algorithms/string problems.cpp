#include<stdio.h>
#include<strings.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
#define N 10

void convertToOnes(char binary[]){
	
	int i = 0;
	
	while(binary[i]){
		if(binary[i] == '0'){
			binary[i] = '1';
		}else{
			binary[i] = '0';
		}
		i++;
	}
}

void convertToTwos(char binary[]){
	convertToOnes(binary);
	printf("%s\n",binary);
	char carry = '1';
	int i = strlen(binary)-1;
	while(i >= 0){
		if(carry == '1'){
			if(binary[i] == '1'){
				carry = '1';
				binary[i] = '0';
			}else{
				carry = '0';
				binary[i] = '1';
			}
		}
		i--;
	}
}

void printZigZag(char str[], int jump){
	
	int len = strlen(str);
	int row = 0;
	int dir = 0; //direction 0=>down and 1=>up
	
	string zigzagged[jump];
	for(int i = 0; str[i]; i++){
		
		//printf("%c",str[i+row+j]);
		zigzagged[row].push_back(str[i]);
		if(row == jump-1){
			dir = 1;
		}else if(row == 0){
			dir = 0;
		}
		(dir == 0)? (row++):(row--);
	}
	
	for(int i = 0; i < jump; i++){
		cout<<zigzagged[i];
	}
}

//Print all palindromic partition of string
//ex : nitin => n i t i n ,n iti n,nitin
//after each palindrome put spaces...
void print_pal_par(string str){
	
	//print single length palindromic partition

	
	vector<string> result;
	//print n-length (2,3,4,.....)palindromic partition
	int len = str.length();
	bool sol[len][len];
	
	for(int chain = 1; chain <= len; chain++){
		for(int i = 0; i < len-chain+1; i++){
			int j = i+chain-1;
			if(str[i] == str[j]){
				if(chain == 1 || chain == 2){
					sol[i][j] = true;
				}else{
					sol[i][j] = sol[i+1][j-1];
				}
				if(sol[i][j]){
					string res;
					
					int k = 0,m = i;
					while(m != j+1){
						res.push_back(str[m++]);
					}
					
					result.push_back(res);
				}
			}else{
				sol[i][j] = false;
			}
		}
	}
	
	for(int i = 0; i < result.size(); i++){
		cout<<result.at(i)<<endl;
	}
}

int main(){
	
	char binary[N];
	/*{
		scanf("%s",binary);
	
		convertToOnes(binary);
		printf("%s\n",binary);
	
		convertToTwos(binary);
		printf("%s\n",binary);
	}*/
	auto p = new string("abc");
	cout<<*p<<endl;
	{
		printZigZag("GEEKSFORGEEKS",3);
	}
	
	{
		char str[] = "nitin";
		print_pal_par(str);
	}
	return 0;
}
