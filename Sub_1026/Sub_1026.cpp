#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

void getSum(unsigned int A,unsigned int B,unsigned int m)
{
	unsigned int C = A + B;
	char str[100];
	int index = 0;
	while(C)
	{
		str[index++] = C%m + '0';
		C = C/m;
	}
	str[index] = '/0';
	if(index == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		while(index > 0)
		{
			cout << str[index-1];
			index--;
		}
		cout << endl;
	}

}

int main()
{
	unsigned int A,B,m;
	while(cin >> m && m != 0)
	{
		cin >> A >> B ;
		if( m > 1 && m < 10)
		{
			getSum(A,B,m);
		}
	}
	system("pause");
	return 0;
}