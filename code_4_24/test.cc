#include <iostream>
using namespace std;

class Person
{
public:
  virtual void BuyTicket()
  {
    cout << "买票-全价" << endl;
  }
};

class Student : public Person
{
public:
  virtual void BuyTicket()
  {
    cout << "买票-半价" << endl;
  }  
};

void Func(Person& p)
{
  p.BuyTicket();
}

/*int main()
{
  int i = 1;
  double d = 2.22;
  
  cout << i; //cout.operator<<(int)
  cout << d; //cout.operator<<(double)
  
  return 0;
}*/


int main()
{
  Person p;
  Student s;

  Func(p);
  Func(s);

  return 0;
}





