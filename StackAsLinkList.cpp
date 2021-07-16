#include <iostream>
using namespace std;
const int array_size=10;
  /*struct Stack 
   {public:
	    int data;
	    Stack* next;
	    int top=-1;
   };
class Implementation 
{public:
	bool IsEmpty(struct Stack* pointer) 
	{
		if (pointer->top == -1)
		{
			return true;
		}
		else 
		{
			false;
		}
	}
	void Push(struct Stack* pointer, int value)
	{
		Stack* newnode = new Stack();
		pointer->next=newnode;
		pointer->data= value;
		pointer->top++;
	}
    int Pop(struct Stack* pointer)
	{
		Stack* temp = new Stack();
		int value = pointer->data;
		temp = pointer->next;
		pointer->next = pointer->next->next;
		delete temp;
	}
	int Top(struct Stack* pointer)
	{
		return (pointer->Stack[pointer->top];
	}
};
int main() 
{
	Stack* pointer = new Stack();
	 Implementation* I = new class Implementation();

	 I->Push(pointer, 5);;



}*/
#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
class Implement {
public:
	Node* top = NULL;
	bool IsEmpty()
	{
		return(top == NULL);
	}
	void push(int val) {
		struct Node* newnode = new Node();
		//(struct Node*)malloc(sizeof(struct Node));
		newnode->data = val;
		newnode->next = top;
		top = newnode;
	}
	void pop() {
		if (top == NULL)
			cout << "Stack Underflow" << endl;
		else {
			cout << "The popped element is " << top->data << endl;
			top = top->next;
		}
	}
	void display() {
		struct Node* ptr;
		if (top == NULL)
			cout << "stack is empty";
		else {
			ptr = top;
			cout << "Stack elements are: ";
			while (ptr != NULL) {
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
		}
	}
};
	int main()
	{
		Implement* I = new Implement();
		I->push(5);
		I->push(8);
		I->push(10);

		I->pop();
		I->display();
		I->IsEmpty();

	}