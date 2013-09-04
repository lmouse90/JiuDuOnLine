#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

string myAdd(string A,string B);
string myMinus(string A, string B);
string myMultiple(string A,string B);
string myReverse(string str);

string removePreZero(string str)
{
	int len = str.size();
	int i = 0;
	while(i < len)
	{
		if(str[i] == '0')
			i++;
		else break;
	}
	string dst;
	if(i < len)
	{
		dst = str.substr(i,len-i);
	}
	else dst = "0";
	return dst;
}

void printString(string str)
{
	int len = str.size();
	int flag = false;
	int i = 0;
	while(i < len)
	{
		if(flag)
		{
			cout << str[i];
		}
		else
		{
			if(str[i] != '0')
			{
				flag = true;
				cout << str[i];
			}
		}
		i++;
	}
	cout << endl;
}

string myAdd(string A,string B)
{
	int lenA = A.size();
	int lenB = B.size();
	int maxLen = max(lenA,lenB);
	string C(maxLen + 1,'0');
	string tmpA = A;
	string tmpB = B;


	if(A[0] == '-' && B[0] == '-')
	{
		tmpA = A.substr(1,lenA-1);
		tmpB = B.substr(1,lenB-1);
		C = myAdd(tmpA,tmpB);
		string tmpC = C.insert(0,"-");
		return tmpC;
	}
	else if(A[0] == '-' && B[0] != '-')
	{
		tmpA = A.substr(1,lenA-1);
		tmpB = B;
		if(B[0] == '+')
		{
			tmpB = B.substr(1,lenB-1);
		}
		C = myMinus(tmpB,tmpA);
		return C;
	}
	else if(A[0] != '-' && B[0] == '-')
	{
		tmpB = B.substr(1,lenB-1);
		tmpA = A;
		if(A[0] == '+')
		{
			tmpA = A.substr(1,lenA-1);
		}
		C = myMinus(tmpA,tmpB);
		return C;
	}

	if(A[0] == '+') tmpA = A.substr(1,lenA-1);
	if(B[0] == '+') tmpB = B.substr(1,lenB-1);

	int flag = 0;
	lenA = tmpA.size() - 1;
	lenB = tmpB.size() - 1;
	int lenC = C.size() - 1;
	int index = 0;
	while(lenA >= 0 && lenB >= 0)
	{
		int value = tmpA[lenA--] - '0' + tmpB[lenB--] - '0' + flag;
		if(value >= 10) flag = 1;
		else flag = 0;
		C[lenC--] = value%10 + '0';
	}

	while(lenA >= 0)
	{
		int value = tmpA[lenA--]  + flag - '0';
		if(value >= 10) flag = 1;
		else flag = 0;
		C[lenC--] = value%10 + '0';
	}

	while(lenB >= 0)
	{
		int value = tmpB[lenB--] + flag - '0';
		if(value >= 10) flag = 1;
		else flag = 0;
		C[lenC--] = value%10 + '0';
	}
	if(flag) C[lenC] = '1';
	return removePreZero(C);

}

string myMinus(string A,string B)
{
	int lenA = A.size();
	int lenB = B.size();
	int maxLen = max(lenA,lenB);
	string C(maxLen + 1,'0');

	string tmpA = A;
	string tmpB = B;

	if(A[0] == '-' && B[0] == '-')
	{
		tmpA = A.substr(1,lenA-1);
		tmpB = B.substr(1,lenB-1);
		C = myMinus(tmpB,tmpA); 
		return C;
	}
	else if(A[0] == '-' && B[0] != '-')
	{
		tmpA = A.substr(1,lenA-1);
		tmpB = B;
		C = myAdd(tmpA,tmpB);
		string tmpC = C.insert(0,"-");
		return tmpC;
	}
	else if(A[0] != '-' && B[0] == '-')
	{
		tmpB = B.substr(1,lenB-1);
		tmpA = A;
		C = myAdd(tmpA,tmpB);
		return C;
	}
	
	if(A[0] == '+') tmpA = A.substr(1,lenA-1);
	if(B[0] == '+') tmpB = B.substr(1,lenB-1);

	lenA = tmpA.size() - 1;
	lenB = tmpB.size() - 1;

	bool sign = true;
	if( lenA < lenB || (lenA == lenB && tmpB.compare(tmpA) == 1))
	{
		sign = false;
		string tmp = tmpA;
		tmpA = tmpB;
		tmpB = tmp;

		int tmpLen = lenA;
		lenA = lenB;
		lenB = tmpLen;
	}
	int flag = 0;
	int lenC = C.size() - 1;
	while(lenA >= 0 && lenB >= 0)
	{
		int value = tmpA[lenA--] - tmpB[lenB--] + flag;
		if(value >= 0)
		{
			C[lenC--] = value + '0';
			flag = 0;
		}
		else
		{
			C[lenC--] = value + 10 + '0';
			flag = -1;
		}
	}
	while(lenA >= 0)
	{
		int value = tmpA[lenA--] + flag - '0';
		if(value >= 0)
		{
			C[lenC--] = value + '0';
			flag = 0;
		}
		else
		{
			C[lenC--] = value + 10 + '0';
			flag = -1;
		}
	}
	if(!sign) C[lenC] = '-';
	return removePreZero(C);

}

string myMultiple(string A,string B)
{
	return A;
}


int main()
{
	string A,B;
	char str[403];
	while(cin >> str)
	{
		A = str;
		cin >> str;
		B = str;

		string C = myAdd(A,B);
		cout << C.data() << endl;

		string D = myMinus(A,B);
		cout << D.data() << endl;
	}

	system("pause");
	return 0;
}