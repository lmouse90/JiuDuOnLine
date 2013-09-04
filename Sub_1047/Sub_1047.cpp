#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
	if(num < 2) return false;
	int i=2;
	while(i <= sqrt(static_cast<double>(num)))
	{
		if(num % i == 0)
			return false;

		i++;
	}
	return true;
}

int main()
{
	int num;
	while(cin >> num)
	{
		bool flag = isPrime(num);
		if(flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}