#include <iostream>
using namespace std;
int main()
{
	int n,sum;
	while(cin >> n >> sum)
	{
		if(n > 1)
		{
			int *arr = new int[n];
			int i;
			for(i=0; i<n; i++)
			{
				cin >> arr[i];
			}
			int *pre = arr;
			int *last = arr + n - 1;
			long long minMul = 0x7fffffffffffffff;
			bool bFound = false;
			int start,end;
			while(pre < last)
			{
				int tmpSum = *pre + *last;
				if(tmpSum == sum)
				{
					bFound = true;
					long long tmpMul = (*pre) * (*last);
					if(tmpMul < minMul)
					{
						minMul = tmpMul;
						start = pre - arr;
						end = last - arr;
					}
					last--;
				}
				else if(tmpSum > sum)
				{
					last--;
				}
				else
				{
					pre++;
				}
			}
			if(bFound)
			{
				cout << arr[start] << " " << arr[end] << endl;
			}
			else
			{
				cout << -1 << " " << -1 << endl;
			}
			delete[] arr;
		}
	}
	return 0;
}