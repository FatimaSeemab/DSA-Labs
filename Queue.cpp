#include <iostream>

using namespace std;
const int Max_Size = 20;

class Implement 
{public:
	int items[Max_Size];
	//Array of int type is declared
	//two integer elements indicate front and last end of queue
	int front;
	int rear;
	//Method to craete queue
	void CreationOfQueue()
	{//in Queue initially rear is assigned -1 and front is 0
		front = 0;
		rear = -1;
	}
	bool isFULL() 
	{//if no of elments in array equal to its size return true 
		return (front == Max_Size-1);
	}
	bool isEmpty() 
	{//rear is less than front only when queue is just initialized and have no element
		return(rear<front);
	}
	void EnQueue(int value)
	{//To add an element in queue we first check it should not be full
		if (!isFULL())
		{//rear is incremented
			rear++;
			items[rear] = value;
			//A new value is enqueued in list at rear position
		}
	}
	int Dequeue()
	{//To remove an element in queue we first check it should not be empty
		if (!isEmpty())
        {//To return this element later on,we store it in x variable 
			int x = items[front];
			//front is incremented
			front++;
			return x;
		}
	}
	void printFrontandEnd() 
	{   cout<<items[front]<<endl;
		cout << items[rear] << endl;
	}
	//to remove all the elements in queue
	int cancel()
	{//if not empty
		int p;
		if (!isEmpty())
		{//loop continues until the last element in queue is dequeued
			while (front!=(rear+1))
			{
			 p=Dequeue();
			}
		}
		//returns last element which is dequeued;
		return p;
	}
};
int main() 
{
	Implement* I = new Implement();
	I->CreationOfQueue();
	I->EnQueue(5);
	I->EnQueue(8);
	I->EnQueue(10);
	I->printFrontandEnd();
	//I->Dequeue();
	I->cancel();

	//I->printFrontandEnd();

}