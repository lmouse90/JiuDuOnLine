#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct BSTreeNode
{
	int data;
	BSTreeNode* pLeft;
	BSTreeNode* pRight;
	BSTreeNode(int _data,BSTreeNode* left,BSTreeNode* right):data(_data),pLeft(NULL),pRight(NULL){}
};

void buildTree(BSTreeNode* &root,int data)
{
	if(root == NULL)
	{
		root = new BSTreeNode(data,NULL,NULL);
	}
	else
	{
		if(root->data > data)
		{
			buildTree(root->pLeft,data);
		}
		else
		{
			buildTree(root->pRight,data);
		}
	}
}

bool isEqual(BSTreeNode* a,BSTreeNode* b)
{
	if(a == NULL && b == NULL) return true;
	else
	{
		if(a->data == b->data)
		{
			return isEqual(a->pLeft,b->pLeft) && isEqual(a->pRight,b->pRight);
		}
		else return false;
	}
}

void emptyTree(BSTreeNode* &root)
{
	if(root == NULL) return;

}
int main()
{
	int n;
	
	while(cin >> n && n != 0)
	{
		char str[10];
		BSTreeNode **Root = new BSTreeNode *[n+1];
	
		int i = 0;
		while(i <= n)
		{
			Root[i] = NULL;
			cin >> str;
			int len = strlen(str);
			for(int index=0; index<len; index++)
			{
				buildTree(Root[i],str[index]-'0');
			}
			i++;
		}

		bool flag = true;
		for(i=1; i<=n; i++)
		{
			flag = isEqual(Root[0],Root[i]);
			if(flag)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}

	}

	system("pause");
	return 0;
}