/*
��Ŀ������
JOBDU�������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
���룺
ÿ�����԰���Ϊһ�У���ʾһ��Ӣ�ľ��ӡ�
���Ǳ�֤һ�����ӵĵ��������ᳬ��600��ÿ�����ʵĳ���Ҳ���ᳬ��30��������Ҫע�����Fish�Ǹ�����С�ڵ��ˣ���ʱ�����������м���ܻ��кܶ�ո�Ϊ�˷���������������Ϊһ�е��ַ��������ᳬ��50000���������ſ��Ժ���ͨ��ĸһ������
�����
��Ӧÿ�����԰������ѷ�ת�����ȷ�ľ��ӵ������һ�С�
�������룺
student. a am I
I'm a Freshman and I like JOBDU!
���������
I am a student.
JOBDU! like I and Freshman a I'm
*/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

void swapStr(char *str, int begin ,int end)
{
	char* bS = str + begin;
	char* eS = str + end;
	while(bS < eS)
	{
		char tmp = *bS;
		*bS = *eS;
		*eS = tmp;
		bS++;
		eS--;
	}
}

int main()
{
	char str[50000];
	while(gets(str))
	{
		int length = strlen(str);
		swapStr(str,0,length-1);

		int i = 0;
		int begin = 0, end = 0;
		bool bBegin = false;
		bool bEnd = false;
		while(i < length)
		{
			if(!bBegin && str[i] != ' ')
			{
				bBegin = true;
				begin = i;
			}
			if(bBegin)
			{
				if(str[i] != ' ')
				{
					end = i;
				}
				else
				{
					bEnd = true;
				}
			}
			if(bEnd)
			{
				swapStr(str,begin,end);
				bEnd = false;
				bBegin = false;
			}
			i++;
		}
		if(bBegin)
		{
			swapStr(str,begin,end);
		}



		cout << str << endl;
	}
	return 0;
}