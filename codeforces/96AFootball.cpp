#include<iostream>
using namespace std;

int main()
{
int cnt = 0;
string p;
cin>>p;
int i = 0;

while(i < p.length())
{
if(p[i] == '1')
{
int k = i+1;
while(p[i] == p[k])
{
  if(k-i == 1)
    cnt+=2;
  else
    cnt++;
k++;
}
if(cnt >= 7){
cout<<"YES";
break;
}
else
{
cnt = 0;
i = k;
}
}
if(p[i] == '0')
{
int k = i+1;
while(p[i] == p[k])
{
  if(k-i == 1)
    cnt +=2;
  else
   cnt++;
k++;
}
if(cnt >= 7){
cout<<"YES";
break;
}
else
{
cnt = 0;
i = k;
}
}

}

if(cnt < 7)
  cout<<"NO";
return 0;
}
