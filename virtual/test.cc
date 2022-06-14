#include <iostream>
using namespace std;

//class A
//{
//public:
//	int _a;
//};//sizeof(A) = 4
//
//class B : virtual public A
//{
//};//sizeof(B) = 4 + 4 = 8
//
//class C : virtual public A
//{
//};//sizeof(C) = 4 + 4 = 8
//
//class D : public B, public C
//{
//};//sizeof(D) = 8 + 8 - 1 * 4 = 12

/*int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;

	return 0;
}*/

/*int main()
{
	int i = 1;
	double d = 2.22;
	
	cout << i;//cout.operator<<(int);
	cout << d;//cout.operator<<(double);


	return 0;
}*/
///////////////////////////////////////////////////////////////

//class A
//{};
//class B : public A
//{};
//class Person
//{
//public:
//	virtual A& BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		//return A();
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B& BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//		//return B();
//	}
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
///*void Func(Student s)
//{
//	s.BuyTicket();
//}*/
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//	
//	//st.BuyTicket();
//	//st.Person::BuyTicket();
//
//	return 0;
//

class Base
{
public:
	virtual void func1()
	{
		cout << "void func1()" << endl;
	}

	virtual void func2()
	{
		cout << "void func2()" << endl;
	}
private:
	int _b = 1;
	char _ch = 'A';
};

int main()
{
	cout << sizeof(Base) << endl;
	Base bb;

	return 0;
}



