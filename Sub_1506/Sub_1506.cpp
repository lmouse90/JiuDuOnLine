/*
题目描述：
	求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
	输入：
	输入可能包含多个测试样例。
	对于每个测试案例，输入为一个整数n(1<= n<=100000)。
	输出：
	对应每个测试案例，
	输出1+2+3+…+n的值。
	样例输入：
	3
	5
	样例输出：
	6
	15
*/
#include <iostream>
using namespace std;

class Add
{
public:
	
	Add() 
	{
		++N; 
		sum += N;
	}
	
	static void reset()
	{
		N = 0;
		sum = 0;
	}

	static unsigned int getSum()
	{
		return sum;
	}

private:
	static unsigned int N;
	static unsigned int sum;
};

unsigned int Add::N = 0;
unsigned int Add::sum = 0;

int main()
{
	int n;
	while(cin >> n && n >= 1)
	{
		Add::reset();

		Add *addObect = new Add[n];

		cout << Add::getSum() << endl;

		delete[] addObect;
		addObect = NULL;
	}

	return 0;
}