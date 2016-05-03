#include<iostream>
#include<string>
#include<vector>
using namespace std;

class abc{
	int d;
};
int main(){
	//using a = abc;
	//Infinite loop
	/*
	for(unsigned u = 10; u >= 0; u--){
		cout<<u<<endl;
	}
	*/
	int u = 2.2,z = 5;
	int &ef = u;
	ef = z;
	ef = 6;
	cout<<u<<"\t"<<&ef<<"\t"<<z<<"\t"<<ef<<endl;
	
	unsigned u1 = 35,u2 = 10;
	int i = -45;
	cout<<u1+i<<"\t"<<u1-u2<<"\t"<<u2-u1<<i-u1<<endl;
	
	//int month = 09;  //error
	//cout<<month<<endl;
	
	long double pi = 3.1424523223;
	int a = { 3.1424523223};
	cout<<a<<endl;
	
	int *pt = &a;
	int **ptr = &pt;
	
	int *&r = pt;
	int j = 5;
	int *st = &j;
	r = st;
	cout<<*r<<"\t"<<*pt<<"\t"<<*st<<endl;
	
	int const &r1 = 42;
	cout<<r1<<endl;
	
	double dval = 3.5;
	int const &r5 = dval;
	//int &r5 = dval ; // error
	//r5 = 6 //error const ref
	cout<<dval<<"\t"<<r5<<endl;
	//constexpr int c = 20;
	//cout<<c<<endl;
	
	cout<<"\nMod : "<<(-15)%(-4)<<endl;
	
	float f;
	a = 123456789;
	f = a;
	cout<<"\nf : "<<f<<endl;
	cout<<"\nexp : "<<5*1 + 6*2 + 7*3<<endl;
	++a = 5;
	cout<<a<<endl;
	
	string s1("abc");
	cout<<s1<<endl;
	string s2("bhuwan");
	cout<<s2<<endl;
	s2 = s1;
	s1 = "bhask";
	cout<<s2<<"\t"<<s1<<endl;
	//getline(cin,s2);
	cout<<s2<<endl;
	vector<int> arr{1,2,3,4,5};
	//cin>>s2;
	//cout<<s2<<endl;
	//press ctrl-z to break
	//auto len = s2.size();
	for(int i = 0; i < s2.size(); i++){
		//char &ch = s2[i];
		//ch = toupper(ch);
		s2[i] = toupper(s2[i]);
	}
	cout<<s2<<endl;
	//cout<<"\nlenf: "<<len<<endl;
	while(cin>>s2){
		cout<<s2<<endl;
	}
	char ch;  //problem
	while((ch == getchar())!= EOF)
	{
		cout<<putchar(ch);
	}
	
	//features available in c++ 11
	//auto,decltype,vector initialization like array
	
}
