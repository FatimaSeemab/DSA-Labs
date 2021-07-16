#include<iostream>
using namespace std;
class ListNode;
struct ListNode
{
	int data;
	ListNode* next;
};
class Node {
public:
	int data;
	ListNode* Next;
};

class Graph
{
public:
	Graph()
	{


	}
	Graph(Node** arr, int n)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i]->Next = new ListNode();
		}
	}
	void InsertVertices(Node* a, int v1)
	{
		a->data = 1;
	}
	void InsertEdges(Node** arr,int v1,int v2)
	{
		ListNode* node=new ListNode();

		if (v1 == 0)
		{
			
			if (arr[0]->Next->next == NULL)
			{
				
				arr[0]->Next->next = node;
				arr[0]->Next->next->data = v2;
				arr[0]->Next->next->next = NULL;
			}
			else
			{
				ListNode* temp = arr[0]->Next->next;
				ListNode* ptemp = NULL;
				while (temp != NULL)
				{
					ptemp = temp;
					temp = temp->next;
				}
				temp = node;
				ptemp->next = temp;
				temp->next = NULL;
				temp->data = v2;
			}
		}
		if (v1 == 1)
		{
			if (arr[1]->Next == NULL)
			{
				arr[1]->Next = node;
				arr[1]->Next->data = v2;
				arr[1]->Next->next = NULL;
			}
			else
			{
				ListNode* temp = arr[1]->Next->next;
				while (temp != NULL)
				{
					temp = temp->next;
				}
				temp = node;
				temp->next = NULL;
				temp->data = v2;

			}
		}
		if (v1 == 2)
		{
			if (arr[2]->Next == NULL)
			{
				arr[2]->Next = node;
				arr[2]->Next->data = v2;
				arr[2]->Next->next = NULL;
			}
			else
			{
				ListNode* temp = arr[2]->Next->next;
				while (temp != NULL)
				{
					temp = temp->next;
				}
				temp = node;
				temp->next = NULL;
				temp->data = v2;

			}
		}
		if (v1 == 3)
		{
			if (arr[3]->Next == NULL)
			{
				arr[3]->Next = node;
				arr[3]->Next->data = v2;
				arr[3]->Next->next = NULL;
			}
			else
			{
				ListNode* temp = arr[3]->Next->next;
				while (temp != NULL)
				{
					temp = temp->next;
				}
				temp = node;
				temp->next = NULL;
				temp->data = v2;

			}
		}
		if (v1 == 4)
		{
			if (arr[4]->Next == NULL)
			{
				arr[4]->Next = node;
				arr[4]->Next->data = v2;
				arr[4]->Next->next = NULL;
			}
			else
			{
				ListNode* temp = arr[1]->Next->next;
				while (temp != NULL)
				{
					temp = temp->next;
				}
				temp = node;
				temp->next = NULL;
				temp->data = v2;

			}
		}
	
	}
	void PrintGraph(Node** arr , int v)
	{
		for (int i = 0; i <= v; i++)
		{
			cout << "Connections with vertex " << i << endl;
			ListNode* temp = arr[i]->Next->next;
			while (temp != NULL)
			{
				cout << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}
	}
};
	
	

int main()
{
	Node** arr=new Node*[5];
	for (int i = 0; i < 5; i++)
	{
	 arr[i] = new Node();
	}
    Graph* g= new Graph(arr,5);

	g->InsertVertices(arr[0], 0);
	g->InsertVertices(arr[1], 1);
	g->InsertVertices(arr[2], 2);
	g->InsertVertices(arr[3], 3);
	g->InsertVertices(arr[4], 4);
	g->InsertEdges(arr, 0, 2);
	g->InsertEdges(arr, 0, 3);
	g->InsertEdges(arr, 0, 4);
	g->PrintGraph(arr, 4);

}