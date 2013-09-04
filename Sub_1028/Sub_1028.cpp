#include <iostream>
#include <algorithm>
#include <functional>
#include <conio.h>

using namespace std;

struct Edge
{
	int v1,v2;
	int cost;
	int flag;

	bool operator < (const Edge& e) const
	{
		return cost < e.cost;
	}
};

void make_set(int *parentArr,int *rankArr,int n)
{
	for(int i=0; i<n; i++)
	{
		parentArr[i] = i;
		rankArr[i] = 0;
	}
}

int find_parent(int *parentArr,int x)
{
	while(parentArr[x] != x)
	{
		x = parentArr[x];
	}
	return x;
}

void union_set(Edge edge,int *parentArr,int *rankArr,int &sum,int flag)
{
	int x = find_parent(parentArr,edge.v1);
	int y = find_parent(parentArr,edge.v2);
	if(x == y) return;
	else if(rankArr[x] > rankArr[y])
	{
		parentArr[y] = x;
		if(flag)
		{
			sum += edge.cost;
		}
	}
	else
	{
		parentArr[x] = y;
		if(rankArr[x] == rankArr[y])
		{
			rankArr[y]++;
		}
		if(flag)
		{
			sum += edge.cost;
		}
	}
}

int main()
{
	int nPoints;
	while(cin >> nPoints && nPoints != 0)
	{
		int *parentArr = new int[nPoints];
		int *rankArr = new int[nPoints];
		make_set(parentArr,rankArr,nPoints);

		int edgeNum = nPoints*(nPoints-1)/2;
		Edge *edges = new Edge[edgeNum];
		int sum = 0;
		int v1,v2,cost,flag;
		for(int i=0; i<edgeNum; i++)
		{
			cin >> v1 >> v2 >> cost >> flag;

			edges[i].v1 = v1 -1;
			edges[i].v2 = v2 -1;
			edges[i].cost = cost;
			edges[i].flag = flag;

			if(edges[i].flag)
			{
				union_set(edges[i],parentArr,rankArr,sum,0);
			}
		}
		
		sort(edges,edges+edgeNum,less<Edge>());
		int i = 0,j = 0;
		while(j < edgeNum && i < nPoints-1)
		{
			Edge tmpEdge = edges[j];
			if(find_parent(parentArr,tmpEdge.v1) != find_parent(parentArr,tmpEdge.v2) )
			{
				union_set(tmpEdge,parentArr,rankArr,sum,1);
				i++;
			}
			j++;
		}
		cout << sum << endl;
		delete [] parentArr;
		delete [] rankArr;
		delete [] edges;
	}
}