#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int arr[10];
	int num;
	int i;
	while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8] >> arr[9])
	{
		int maxNum = arr[0];
		for(i=1; i<10; i++)
		{
			if(arr[i] > maxNum) maxNum = arr[i];
		}
		cout << "max=" << maxNum << endl;
	}


	system("pause");
	return 0;
}