//#include<iostream>
//using namespace std;
//class Node { 
//public:
//int data;
//int d;
//char color;
//int  p;
//Node* next;
//};
//class AL {
//public:
//	Node* start;
//	Node* last;
//	Node* temp;
//	Node* loc;
//	Node* ploc;
//	//Constructor of link list 
//	//creates an empty list
//	AL()
//	{
//		start = nullptr;
//		last = nullptr;
//	}
//	//function return whether a list contains any element or not
//	bool isEmpty()
//	{
//		return (start == nullptr);
//	}
//	//Method to insert an element at front of list 
//	void insertatFront(int value)
//	{
//		Node* newnode = new Node();
//		//an object of listNode class iscreated
//		newnode->data = value;
//		//object of this data part is given value
//		if (isEmpty())
//		{
//			last = newnode;
//			start = newnode;
//		}
//		//if list is empty,After insertion of first element both start and last     Pointers point to it.
//		else
//		{
//			newnode->data = value;
//			newnode->next = start;
//			start = newnode;
//			//start pointer is pointed to new node
//		}
//	}
//	void printLinkList()
//	{
//		//if list is empty,method will return
//		if (isEmpty())
//		{
//			cout << "nothing to show u";
//			return;
//		}
//
//		temp = start;
//		//condition valid tills the last of list
//		while (temp != last->next)
//		{
//			cout << temp->data;
//			//displays the element
//			temp = temp->next;
//			// temp pointer is incremented
//		}
//		cout << endl;
//	}
//	//Method to  insert element at the end of list
//	void InsertAtend(int value)
//	{
//		Node* newnode = new Node();
//		newnode->data = value;
//		//if List is empty,both start and last pointers ill be updates
//		if (isEmpty())
//		{
//			start = newnode;
//			last = newnode;
//		}
//		//if list contains any element,only last pointer will be updated
//		else
//		{
//			last->next = newnode;
//			last = newnode;
//		}
//
//	}
//	//Method to search a value
//	void Search(int value)
//	{//if list is empty,method will return
//		if (isEmpty())
//		{
//			cout << "There is no list to found";
//			return;
//		}
//		//Location and predecessor of location is initialized
//		loc = start;
//		ploc = NULL;
//		//Loop continues until list is finished or searched value will become greater then the currnt value of List
//		while ((loc != NULL) && (loc->data < value))
//		{//Whenever a value is found,function will return
//			if (loc->data == value)
//			{
//				return;
//			}
//			//stores the previous location of pointer
//			ploc = loc;
//			//Loc pointer is pointed to next
//			loc = loc->next;
//		}
//		//To make loc null when a value is not found
//		if ((loc != NULL) && ((loc->data) != value))
//		{
//			loc = NULL;
//		}
//
//
//	}
//	// Method to insert an element at its sorted position
//	void InsertSorted(int value)
//	{// searcches the value in list
//		Search(value);
//		//when value is found in list
//		if (loc != NULL)
//		{
//			cout << "value already exist in list";
//
//		}
//		//when value is in list and its logical position is at front
//		if ((loc == NULL) && (ploc == NULL))
//		{
//			insertatFront(value);
//
//		}
//		//If value is not in list and its position is not at front
//		if ((loc == NULL) && (ploc != NULL))
//		{
//			Node* newnode = new Node();
//			//new object is created
//			newnode->data = value;
//			//pointed to appropriate position
//			newnode->next = ploc->next;
//			ploc->next = newnode;
//			//when elements logical position is at end
//			if (ploc == last)
//			{
//				last = newnode;
//			}
//
//		}
//
//	}
//
//};
//class ANode {
//public:
//	int data;
//	AL* list;
//	ANode() { list = new AL(); }
//};
//class Graph {
//public:
//	ANode* a[5];
//	void insertvertices(int i) {
//		
//			a[i] = new ANode();
//			a[i]->data = i + 1;
//		
//	
//	}
//	void insertedge(int src,int dest)
//	{
//			a[src]->list->insertatFront(dest);
//	}
//	void BFS(int src)
//	{
//	
//	
//	
//	
//	}
//};
//int main()
//{
//
//	//Breadth first search
//	//a[0]->list
//}