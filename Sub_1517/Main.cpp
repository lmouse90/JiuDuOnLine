#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
	int s_data;
	Node* s_next;
	Node(int data,Node* next):s_data(data),s_next(NULL){}
};

void buildLink(Node* &root,int data)
{
	if(root == NULL)
	{
		root = new Node(data,NULL);
		return;
	}
	Node* p = root;
	Node* tmp = new Node(data,NULL);
	if(p->s_next == NULL)
	{
		p->s_next = tmp;
	}
	else
	{
		while(p->s_next != NULL)
		{
			p = p->s_next;
		}
		p->s_next = tmp;
	}
}

int findReverseK(const Node* root,int length, int k)
{
	if(length == k) return root->s_data;
	else
	{
		Node *pFast = const_cast<Node*>(root);
		Node *pSlow = pFast;
		while(k)
		{
			pFast = pFast->s_next;
			k--;
		}
		while(pFast != NULL)
		{
			pFast = pFast->s_next;
			pSlow = pSlow->s_next;
		}
		return pSlow->s_data;
	}
}

void clearLink(Node* &root)
{
	while(root->s_next != NULL)
	{
		Node *tmp = root;
		root = root->s_next;
		delete tmp;
	}
	delete root;
	root = NULL;
}

int main()
{
	int allNum,k;
	while(cin >> allNum >> k)
	{
		Node* root = NULL;
		for(int i=0; i<allNum; i++)
		{
			int tmpData;
			cin >> tmpData;
			buildLink(root,tmpData);
		}
		if(k <= 0 || k > allNum) cout << "NULL" << endl;
		else cout << findReverseK(root,allNum,k) << endl;

		clearLink(root);
	}

	system("pause");
	return 0;
}