#include <iostream>
#include <conio.h>

using namespace std;



int main()
{
	int n;
	int i;
	while(cin >> n && n >0)
	{
		int *arr = new int[n];
		for(i=0; i<n; i++)
		{
			int num;
			cin >> num;
			arr[i] = num;
		}


		int start = 0, end = 0;
		int sum = 0;
		int maxSum = 0x80000000;
		int nNext = 0;
		int tmpBegin;
		for(i=0; i<n; i++)
		{
			if(maxSum < 0)
			{
				start = i;
				end = i;
			}

			if(sum < 0)
			{
				sum = 0;
				if(maxSum > 0)
				{
					nNext = 1;
				}
			}

			sum += arr[i];
			if(sum > 0 && nNext == 1)
			{
				tmpBegin = i;
				nNext++;
			}

			if(sum > maxSum && sum >= 0)
			{
				maxSum = sum;
				if(nNext)
				{
					start = tmpBegin;
					nNext = 0;
				}
				end = i;
			}



		}
		if(maxSum < 0) cout << 0 << " " << arr[0] << " " << arr[n-1] << endl;
		else cout << maxSum << " " << arr[start] << " " << arr[end] << endl;
		delete [] arr;
	}
	system("pause");
	return 0;
}