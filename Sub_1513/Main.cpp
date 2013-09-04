#include <iostream>
#include <conio.h>

using namespace std;

int count(int num)
{
	int tmp = 1;
	int index = 0;
	int countOne = 0;
	while(index++ < 32)
	{
		if(num & tmp) countOne++;
		tmp = tmp << 1;
	}
	return countOne;
}

int main()
{
	int allNum,num;
	cin >> allNum;
	int index = 0;
	if(allNum > 0)
	{
		int *arr = new int[allNum];
		while(index < allNum)
		{
			cin >> num;
			arr[index++] = num;
		}
		for(index=0; index<allNum; index++)
		{
			cout << count(arr[index]) << endl;
		}
		delete []arr;
	}
	system("pause");
	return 0;
}