#include <iostream>

using namespace std;

void completeNum(int n)
{
	if(n <6) return;
	int *arr = new int[n+1];
	int i,j;
	for(i=0; i<n+1; i++)
	{
		arr[i] = 0;
	}
	for(i=1; i<n+1; i++)
	{
		for(j= 2*i; j<n+1;)
		{
			arr[j] += i;
			j += i;;
		}
	}
	int count = 0;
	for(i=6; i<n+1; i++)
	{
		if(arr[i] == i) count++;
	}
	if(count)
	{
		for(i=6; i<n+1 && count; i++)
		{
			if(arr[i] == i)
			{
				cout << i;
				if(count-- > 1) cout << " ";
			}
		}
	}
	delete [] arr;
}

int main()
{
	int num;
	while(cin >> num)
	{
		completeNum(num);
	}
	return 0;
}