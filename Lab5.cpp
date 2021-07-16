#include <iostream>;
using namespace std;
const int array_size = 10;
struct stack {
public:
	int top = -1;
	int stack[array_size];
	bool IsEmpty(struct stack* pointer)
	{
		if (top == -1)
		{
			cout << "stack underflow";
			return true;
		}
		else { return false; }
	}
	bool IsFull(struct stack* pointer)
	{
		if (top == array_size)
		{
			cout << "stack overflow";
			return true;
		}
		else { return false; }
	}
	void Push(struct stack* pointer, int value)
	{
		pointer->top++;
		pointer->stack[pointer->top] = value;
	}
	int pop(struct stack* pointer)
	{
		return (pointer->stack[pointer->top--]);
	}
	int Top(struct stack* pointer)
	{
		if (IsEmpty(pointer))
		{
			return -1;
		}
		else
			return (pointer->stack[pointer->top]);
	}
};

int main()
{
	struct stack* p= NULL;
	
	p->IsEmpty(p);
	p->IsFull(p);
	p->pop(p);
	p->Push(p, 5);
	p->Top(p);

}