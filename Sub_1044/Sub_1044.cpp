#include <stdio.h>
#include <string>
#include <conio.h>
using namespace std;
long comb(int m, int n)
{
	int i;
	long temp1, temp2;
	temp1 = temp2 = 1;
	for(i = 0; i < n; ++i)
	{
		temp1 *= m - i;
		temp2 *= n - i;
	}
	return temp1/temp2;
}
long analysis(string str1, string str2, int m)
{
	long sum;
	int count, p;
	string temp1, temp2;
	if(1 == str1.length()) return 1;
	else
	{
		str1 = str1.substr(1, str1.length() - 1);
		str2 = str2.substr(0, str2.length() - 1);
		count = 0;
		sum = 1;
		while(0 != str1.length())
		{
			++count;
			p = str2.find(str1[0], 0);
			temp1 = str1.substr(0, p + 1);
			temp2 = str2.substr(0, p + 1);
			str1 = str1.substr(p + 1, str1.length() - p - 1);
			str2 = str2.substr(p + 1, str2.length() - p - 1);
			sum *= analysis(temp1, temp2, m);
		}
		return comb(m , count)*sum;
	}
}
int main()
{
	char buf1[50];
	char buf2[50];
	string str1, str2;
	long sum;
	int m;
	while(EOF != scanf("%d", &m))
	{
		if(0 == m) break;
		scanf("%s %s", buf1, buf2);
		str1 = buf1;
		str2 = buf2;
		sum = analysis(str1, str2, m);
		printf("%ld\n", sum);
	}

	system("pause");
	return 0;
}