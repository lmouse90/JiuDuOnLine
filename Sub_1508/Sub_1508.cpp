/*
��Ŀ������
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
���룺
������ܰ����������������
����ÿ�����԰���������Ϊһ���Ϸ����߷Ƿ����ַ���������һ������n(1<= n<=10000000)��
�����
��Ӧÿ�����԰�����
������Ϊһ���Ϸ����ַ���(������һ������)����������������
������Ϊһ���Ƿ����ַ������������My God����
�������룺
5
-5
+8
���������
5
-5
8
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;


void char2int(char *str)
{
	int length = strlen(str);
	int sign = 1;
	int begin = 0;
	if(str[0] == '-')
	{
		sign = -1;
		begin = 1;
	}
	else if(str[0] == '+')
	{
		sign = 1;
		begin = 1;
	}
	else if(str[0] < '0' && str[0] > '9')
	{
		cout << "My God" << endl;
		return;
	}
	
	if(begin == length)
	{
		cout << "My God" << endl;
		return;
	}

	long long result = 0;
	int index = 0;
	while(begin < length)
	{
		if(str[begin] >= '0' && str[begin] <= '9')
		{
			result = result * 10 +  (str[begin++] - '0');
		}
		else
		{
			cout << "My God" << endl;
			return;
		}

	}
	result *= sign;
	cout << result << endl;
}

int main()
{
	char str[10];
	while(gets(str))
	{
		if(strlen(str) > 0)
		{
			char2int(str);
		}
		else
		{
			cout << "My God" << endl;
		}

	}
	return 0;
}