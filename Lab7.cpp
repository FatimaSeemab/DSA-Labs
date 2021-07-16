#include <stdio.h>
#include <iostream>
using namespace std;
class LinkList;
class Stack;
class LinkListNode;
LinkListNode* start;
LinkListNode* last;
class Stack {
public:
	LinkListNode* Array[10];
	int top = -1;
	int i = 0;
	LinkList* temp;
	void Push(LinkListNode* node)
	{
		Array[i] = node;
		top++;
		i++;
	}
	LinkListNode* pop()
	{
		LinkListNode* temp = Array[top];
		top--;
		i--;
		return temp;
	}

};
class LinkListNode
{public:
	int data;
	LinkListNode* next;
};
class LinkList
{public:
	

	LinkListNode* AddNode(int value)
	{
		LinkListNode* newnode = new LinkListNode();
		if (start== NULL)
		{
			start = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			last = newnode;
		}
		last->data = value;
	
		return newnode;
	}
	void Revesing()

	{
		Stack* s = new Stack();
		LinkListNode* temp = start;
		while (temp!= NULL)
		{
			s->Push(temp);
		
			temp = temp->next;

		}

		int count = 0;
		while (s->top != -1)
		{
			if (count == 0)
			{
				temp = s->pop();
				start = temp;
				count++;
			}
			else
			{
				temp->next = s->pop();	
				temp = temp->next;
				
			}
			if (s->top == 0)
			{
				temp->next = s->pop();
				last = temp->next;
				last->next = NULL;
				

			}

		}
	}
	void Print()
	{
		LinkListNode* temp;
		temp = start;
		while (temp!= NULL)
		{
			
			cout << temp->data;
			temp = temp->next;
		}
	
	
	}
	


};

int main()
{
	Stack* s = new Stack();
	LinkList* temp=new LinkList();
	temp->AddNode(1);
	temp->AddNode(2);
	temp->AddNode(3);
	temp->AddNode(4);
	temp->AddNode(5);
	cout << "Before Reversing" << endl;
	temp->Print();
	cout << endl<< "After Reversing" << endl;
	temp->Revesing();
	temp->Print();


	
		
		
		


}