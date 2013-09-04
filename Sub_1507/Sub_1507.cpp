#include <iostream>

using namespace std;

int getSum(int m,int n)
{
	int sum = 0;
	int carry = 0;
	while(n)
	{
		sum = m ^ n;
		carry = (m & n) << 1;

		m = sum;
		n = carry;
	}

	return m;
}

class A
{
public:
	A() {cout << "A construct!" << endl;}
	void print() {cout << "A print" << endl;}
};

class B:public A
{
public:
	B() {cout << "B construct!" << endl;}
	void print() {cout << "B print" << endl;}
};

int main()
{
	A *a = new B();
	a->print();
	getchar();
	//int m, n;
	//while(cin >> m >> n)
	//{
	//	if( m >= 1 && m <= 1000000 && n >= 1 && n <= 100000)
	//		cout << getSum(m,n) << endl;
	//}
	return 0;
}

