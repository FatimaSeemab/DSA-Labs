#include<iostream>
using namespace std;
const int Max_Size = 3;
const int n =3;
class Node {
public:
	int data;
	Node* next;
	int d;
	char color;
	int  p;
};
class AL {
public:
	Node* start;
	Node* last;
	Node* temp;
	Node* loc;
	Node* ploc;
	//Constructor of link list 
	//creates an empty list
	AL()
	{
		start = nullptr;
		last = nullptr;
	}
	//function return whether a list contains any element or not
	bool isEmpty()
	{
		return (start == nullptr);
	}
	//Method to insert an element at front of list 
	void insertatFront(int value)
	{
		Node* newnode = new Node();
		//an object of listNode class iscreated
		newnode->data = value;
		//object of this data part is given value
		if (isEmpty())
		{
			last = newnode;
			start = newnode;
		}
		//if list is empty,After insertion of first element both start and last     Pointers point to it.
		else
		{
			newnode->data = value;
			last->next =newnode;
			last = newnode;
			//start pointer is pointed to new node
		}
	}
	void printLinkList()
	{
		//if list is empty,method will return
		if (isEmpty())
		{
			cout << "nothing to show u";
			return;
		}

		temp = start;
		//condition valid tills the last of list
		while (temp != last->next)
		{
			cout << temp->data;
			//displays the element
			temp = temp->next;
			// temp pointer is incremented
		}
		cout << endl;
	}

};
class Implement
{
public:
	int items[Max_Size];
	int front;
	int rear;
	int count;
	void CreationOfQueue()
	{
		int items[Max_Size];
		front = 0;
		rear = -1;
		count = 0;
	}
	bool isFULL()
	{
		if (count == Max_Size)
			return true;
		else
		{
			return false;
		}
	}
	bool isEmpty()
	{
		return(count == 0);
	}
	void EnQueue(int value)
	{
		if (count == Max_Size)
		{
			cout << "cannot enter a vakue" << endl << "QUEUE OVERFLOW";
		}
		rear++;
		if (rear == Max_Size)
		{
			rear = 0;
		}
		items[rear] = value;
		count++;

	}
	int Dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue Underflow";
			return -1;
		}
		else {
			int x = items[front];
			front++;
			if (front == Max_Size)
			{
				front = 0;
			}
			count--;
			return x;
		}

	}

	void printFrontandEnd()
	{
		cout << items[front] << endl;
		cout << items[rear] << endl;
	}
};

class Graph {
public:
	//AL* a;
	AL* a[n];
	int f = 0;
	Graph()
	{
	
		for (int i = 0; i < n; i++)
		{
			a[i] = new AL();
		}
	
	}
	void AddVertex(int data/*,AL *a*/)
	{
		a[f] = new AL();
		a[f]->insertatFront(data);
		f++;
	}
	void AddEdges(int v1,int v2)
	{
		for (int i = 0; i < n; i++)
		{
			if(a[i]->start!=NULL);
			{
				if (a[i]->start->data == v1)
				{
					a[i]->insertatFront(v2);

				}
			}
		}
	
	}
	void PrintGraph()
	{
		for (int i = 0; i < n; i++)
		{
			a[i]->printLinkList();
			cout << endl;
		}
	}
	void BFS(int s){
		Implement* i = new Implement();
		Node* temp;
		for (int i = 0; i < n; i++)
		{
			temp=a[i]->start;
			while (temp != NULL)
			{
				temp->color = 'w';
				temp->p = -1;
				temp->d = 0;
				temp = temp->next;
			}
		}
		for (int i = 0; i < n; i++)
		{
			temp = a[i]->start;
			if (temp != NULL);
			{
				if (temp->data == s)
				{
					temp->color = 'g';
				}
				else {
					temp = temp->next;
				}
			}
		}
		if (!i->isEmpty())
     	{
			i->EnQueue(s);
			while (!i->isEmpty())
			{
			}
         }
		
	
	}
};
int main()
{
	//AL* a[n];
	Graph* g = new Graph();
	
	g->AddVertex(1);
	g->AddVertex(2);
	g->AddVertex(3);
	g->AddEdges(1, 2);
	g->AddEdges(2, 1);
	g->AddEdges(2, 3);
	g->AddEdges(3, 1);
	g->AddEdges(3, 2);
	g->PrintGraph();

}