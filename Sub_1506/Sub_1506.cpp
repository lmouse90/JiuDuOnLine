/*
��Ŀ������
	��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
	���룺
	������ܰ����������������
	����ÿ�����԰���������Ϊһ������n(1<= n<=100000)��
	�����
	��Ӧÿ�����԰�����
	���1+2+3+��+n��ֵ��
	�������룺
	3
	5
	���������
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