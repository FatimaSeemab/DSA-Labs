#include <iostream>
using namespace std;
class Node {
public:
	Node* next;
};
class AList {
public:
	Node* start;
	
	/*AList()
	{
	}
	AList(Node** array,int n)
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = 0;
		}
	
	}*/
	/*void AddVertices(Node** array,int v1,int n)
	{
		for (int i = 0; i < 5; i++)
		{
			array[i]->data = 0;
		}
	
	}
	void AddEdges(Node* array, int v2, int weight)
	{
		Node* x = new Node();
		if (array->next == NULL)
		{
			array[0]->next = x;
			array->data = v1;
			x->next = NULL;

		}
		else
		{
			Node* temp = array;
			while (temp != NULL)
			{
				temp = temp->next;
			}
			temp = x;
			temp->next = NULL;
			x->next = NULL;
		}
		x->data = v2;
	
	
	
	}*/

	void initial(Node* array, int v1, int v2, int weight)
	{
		Node* x = new Node();
		if (array->next == NULL)
		{
			array->next = x;
			x->next = NULL;

		}
		else
		{
			Node* temp = array;
			while (temp != NULL)
			{
				temp = temp->next;
			}
			temp= x;
			temp->next = NULL;
			x->next = NULL;
		}
		//x->data = v2;
	}
	void PrintList(Node* array)
	{
		Node* temp = array;
		while (temp != NULL)
		{
			//cout << temp->data;
			temp = temp->next;
		}
	}

};
int main() {
	int v;
	bool directed;
	cout << "Enter the number of vertices in graph";
	cin >> v;
	cout << "Is graph directed";
	cin >> directed;
	Node* arr[5];
	for (int i = 0; i < 5; i++)
	{
		//arr[0]->data = 0;
		arr[0] = NULL;
		arr[0]->next = NULL;
	}
	/*Node** array = new Node*[v];
	AList* a = new AList(array,v);
	AList* a2=new AList();
	a->initial(array[0],2,4,1);
	a->initial(array[0], 2, 3, 1);
	a->initial(array[0], 2, 1, 1);
	a->PrintList(array[0]);*/


}