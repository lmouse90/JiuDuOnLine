/*
题目描述：
JOBDU最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
输入：
每个测试案例为一行，表示一句英文句子。
我们保证一个句子的单词数不会超过600，每个单词的长度也不会超过30。但是需要注意的是Fish是个不拘小节的人，有时候两个单词中间可能会有很多空格。为了方便起见，你可以认为一行的字符总数不会超过50000个，标点符号可以和普通字母一样处理。
输出：
对应每个测试案例，把翻转后的正确的句子单独输出一行。
样例输入：
student. a am I
I'm a Freshman and I like JOBDU!
样例输出：
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