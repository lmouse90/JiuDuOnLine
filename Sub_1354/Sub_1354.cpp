#include <iostream>
#include <cmath>
using namespace std;

void getSub(int n)
{
	if(n < 3)
	{
		cout << "Pity!" << endl << "#" << endl;
		return;
	}
	int allNum = sqrt(static_cast<double>(n));
	int *arr = new int[allNum];
	int num = 0;
	int i = 2;
	if(n % 2 == 0)
	{
		i = 3;
	}
	else
	{
		arr[0] = 2;
		num++;
	}
	for(; i <= sqrt(static_cast<double>(n)); i++)
	{
		if(n % i == 0)
		{
			arr[num] = i;
			num++;
		}
	}

	bool bExist = false;

	i = 0;
	if(n % 2 != 0)
	{
		bExist = true;	
		i = 1;
	}
	for(; i<num; i++)
	{
		int tmp = n/arr[i];
		if(tmp%2 == 0 && arr[i]%2 == 0)
		{
			continue;;
		}
		else if(arr[i]%2 == 1)
		{
			bExist = true;
			int index = arr[i]/2;
			while(index)
			{
				cout << tmp - index << " ";
				index--;
			}
			cout << tmp << " ";
			index = 1;
			while(index <= arr[i]/2)
			{
				cout << tmp + index << " ";
				index++;
			}
			cout << endl;
		}
		else if(tmp%2 == 1)
		{
			bExist = true;
			int mid = n/(arr[i]*2);
			int index = arr[i];
			while(index)
			{
				cout << mid - index + 1 << " ";
				index--;
			}
			index = 1;
			while(index <= arr[i])
			{
				cout << mid + index << " ";
				index++;
			}
			cout << endl;

		}
	}
	if(n%2 == 1)
	{
		cout << n/2 << " " << n/2 + 1 << endl;
	}
	if(!bExist) cout << "Pity!" << endl;
	cout << "#" << endl;
	delete [] arr;
}

int main()
{
	int n;
	while(cin >> n && n >= 0)
	{
		getSub(n);
	}

	return 0;
}