#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

long long fibonacci(int n)
{
	long long first = 0;
	long long second = 1;
	if(n == 0) return 0;
	if(n == 1) return 1;
	long long result;
	for(int i=2; i<=n; i++)
	{
		result = first + second;
		cout << i << "\t" << result << endl;
		first = second;
		second = result;
	}
	return result;
}

long long fibonacci2(int n)
{
	if(n <= 0) return 0;
	else if(n == 1) return 1;
	else return fibonacci2(n-1) + fibonacci2(n-2);
}
int main()
{
	int n;
	
	while(cin >> n)
	{
		if(n >= 0)
		{
			cout << clock() << endl;
			cout << fibonacci(n) << endl;
			cout << fibonacci2(n) << endl;
			cout << clock() << endl;
		}
	}

	system("pause");
	return 0;
}