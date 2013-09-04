/*
题目描述：
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
输入：
输入可能包含多个测试样例。
对于每个测试案例，输入为一个合法或者非法的字符串，代表一个整数n(1<= n<=10000000)。
输出：
对应每个测试案例，
若输入为一个合法的字符串(即代表一个整数)，则输出这个整数。
若输入为一个非法的字符串，则输出“My God”。
样例输入：
5
-5
+8
样例输出：
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