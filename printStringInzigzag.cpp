#include<iostream>

using namespace std;

string zigzag(string a , int rows)
{
  if(rows <= 1)
    return a;
  string res[rows];
  int j = 0;  //j%rows
  int inc = 1;
  for(int i = 0; i < a.length(); i++)
  {
    res[j] += a[i];
    //cout<<res[j]<<endl;
    
    if(j == 0)
      inc = 1;
    else if(j == rows-1)
      inc = 0;
    
    if(inc)
      j++;
    else if(!inc)
      j--;
  }
  
  string result;
  for(int i = 0; i < rows; i++)
      result += res[i];
  //cout<<result;
  return result;
}

int main()
{
  
  cout<<zigzag("kHAlbLzY8Dr4zR0eeLwvoRFg9r23Y3hEujEqdio0ctLh4jZ1izwLh70R7SAkFsXlZ8UlghCL95yezo5hBxQJ1Td6qFb3jpFrMj8pdvP6M6k7IaXkq21XhpmGNwl7tBe86eZasMW2BGhnqF6gPb1YjCTexgCurS",1)<<endl;
  return 0;
  
}
