#include <iostream>
#include <conio.h>

using namespace std;

int find(int *arr,int left,int right);
int find(int *arr,int n);

int find(int *arr,int n)
{
	int left = 0;
	int right = n-1;
	if(arr[left] < arr[right])
	{
		return arr[left];
	}
	int mid;
	while(left < right)
	{
		mid = left + (right-left)/2;
		if(arr[mid] == arr[left] && arr[mid] == arr[right])
		{
			return find(arr,left,right);
		}
		if(arr[mid] >= arr[0])
		{
			left = mid + 1;
		}
		else if(arr[mid] <= arr[n-1])
		{
			right = mid;
		}
	}
	return arr[right];
}

int find(int *arr,int left,int right)
{
	int result = arr[left];
	for(int i=left+1; i<= right; i++)
	{
		if(arr[i] < result)
		{
			result = arr[i];
		}
	}
	return result;
}

int find2(int *arr,int n)
{
	int result = arr[0];
	int i = 1;
	while(i < n)
	{
		if(arr[i] >= result)
		{
			i++;
		}
		else
		{
			result = arr[i];
			break;
		}
	}
	return result;
}

int main()
{
	int num;
	while(cin >> num)
	{
		if(num > 0)
		{
			int *arr = new int[num];
			for(int i=0; i<num; i++)
			{
				int key;
				cin >> key;
				arr[i] = key;
			}
			cout << find2(arr,num) << endl;
			delete[] arr;
		}
	}

	system("pause");
	return 0;
}