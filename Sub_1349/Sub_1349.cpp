#include <iostream>
using namespace std;

int findLessMax(int *arr,int n,int k);
int findGreaterMin(int *arr,int n,int k);

int findLessMax(int *arr,int n,int k)
{
	int begin = 0, end = n-1, mid;
	while(begin < end -1)
	{
		mid = begin + (end - begin)/2;
		if(arr[mid] >= k)
		{
			end = mid;
		}
		else
			begin = mid;
	}
	if(arr[begin] == k) return begin - 1;
	else if(arr[end] == k) return begin;
	else return -2;
}

int findGreaterMin(int *arr,int n,int k)
{
	int begin = 0, end = n-1, mid;
	while(begin < end - 1)
	{
		mid = begin + (end - begin)/2;
		if(arr[mid] <= k)
		{
			begin = mid;
		}
		else
			end = mid;
	}
	if(arr[end] == k) return end+1;
	else if(arr[begin] == k) return end;
	else return -2;
}

int getPostion(int *arr,int n,int k)
{
	int begin = 0, end = n-1, mid;
	while(begin < end)
	{
		mid = begin + (end - begin)/2;
		if(arr[mid] = k)
		{
			return mid;
		}
		else if(arr[mid] > k)
		{
			end = mid;
		}
		else
		{
			begin = mid;
		}
	}
	return -1;
}

int getFirstK(int* data,int length,int k,int start,int end)
{
	if(start > end)
		return -1;
	int middleIndex = (start + end)/2;
	int middleData = data[middleIndex];

	if(middleData == k)
	{
		if((middleIndex > 0 && data[middleIndex-1] != k) || middleIndex == 0)
		{
			return middleIndex;
		}
		else end = middleIndex - 1;
	}
	else if(middleData > k)
		end = middleIndex - 1;
	else start = middleIndex + 1;

	return getFirstK(data,length,k,start,end);
}

int getLastK(int* data,int length,int k,int start,int end)
{
	if(start > end)
		return -1;
	int middleIndex = (start + end)/2;
	int middleData = data[middleIndex];

	if(middleData == k)
	{
		if((middleIndex < length -1 && data[middleIndex + 1] != k) || middleIndex == length -1)
		{
			return middleIndex;
		}
		else start = middleIndex + 1;
	}
	else if(middleData > k)
		end = middleIndex - 1;
	else start = middleIndex + 1;

	return getLastK(data,length,k,start,end);
}

int getNumOfK(int *arr,int n,int k)
{
	//int num = 1;
	/*int first = findLessMax(arr,n,k);
	int end = findGreaterMin(arr,n,k);
	if(first != -2 && end != -2)
		num = end - first - 1;*/

	/*int index = getPostion(arr,n,k);
	if(index != -1)
	{
		int tmpIndex = index + 1;
		while(tmpIndex < n)
		{
			if(arr[tmpIndex++] == k) num++;
			else break;
		}
		tmpIndex = index - 1;
		while(tmpIndex >= 0)
		{
			if(arr[tmpIndex--] == k) num++;
			else break;
		}
		return num;
	}
	else
	{
		return 0;
	}*/

	int num = 0;
	int first = getFirstK(arr,n,k,0,n-1);
	int last = getLastK(arr,n,k,0,n-1);
	if(first > -1 && last > -1)
		num = last - first + 1;
	return num;
}

int main()
{
	int n;
	while(cin >> n)
	{
		if( n >= 1 && n <= 1000000)
		{
			int *arr = new int[n];
			int i;
			for(i=0; i<n; i++)
			{
				cin >> arr[i];
			}
			int nFind;
			cin >> nFind;
			int *arrFind = new int[nFind];
			for(i=0; i<nFind; i++)
			{
				cin >> arrFind[i];
			}
			for(i=0; i<nFind; i++)
			{
				cout << getNumOfK(arr,n,arrFind[i]) << endl;
			}

			delete[] arrFind;
			delete[] arr;
		}

	}

	return 0;
}