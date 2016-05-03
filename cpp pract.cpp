#include<iostream>
#include<memory>
#include<exception>

using namespace std;

class pr : public exception
{
  virtual const char* what() const throw()
  {
    return "phaltu ka exception !!!";
  }
}ex;

class abc 
{
  int *a;
  int *b;
}ab;

int main()
{
  auto_ptr<int> a(new int);
  *a = 15;
  cout<<*a<<endl;
  try
  {
    throw ex;
  }
  catch(exception &e)
  {
    cout<<e.what();
  }
}
