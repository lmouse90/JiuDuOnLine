#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int N,M;
	int A[10][10],B[10][10],C[10][10];
	while(cin >> M && M > 0)
	{
		cin >> N;
		int i,j;
		for(i=0; i<M; i++)
		{
			for(j=0; j<N; j++)
			{
				cin >> A[i][j];
			}
		}
		for(i=0; i<M; i++)
		{
			for(j=0; j<N; j++)
			{
				cin >> B[i][j];
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		int count = 0;
		bool bAllZero;
		for(i=0; i<M; i++)
		{
			bAllZero = true;
			for(j=0; j<N; j++)
			{
				if(C[i][j] != 0)
				{
					bAllZero = false;
					break;
				}
			}
			if(bAllZero) count++;
		}

		for(j=0; j<N; j++)
		{
			bAllZero = true;
			for(i=0; i<M; i++)
			{
				if(C[i][j] != 0)
				{
					bAllZero = false;
					break;
				}
			}
			if(bAllZero) count++;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}