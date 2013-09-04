#include <iostream>
#include <conio.h>

using namespace std;

long long jump(int n)
{
	if(n <= 0) return 0;
	else if(n == 1) return 1;
	else if(n == 2) return 2;
	else
	{
		long long pre = 3;
		long long result;
		for(int i=3; i<=n; i++)
		{
			result = pre + 1;
			pre += result;
		}
		return result;
	}
}

int main()
{
	int n;

	while(cin >> n)
	{
		if(n >= 0)
		{
			cout << jump(n) << endl;
		}
	}

	system("pause");
	return 0;
}