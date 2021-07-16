#include <iostream>
using namespace std;
//const int n;
/*class CalculateFactorial {
public:
	int factorial;
	int fact(int n)
	{
		cout << " call to fact value " << n << endl;
		if (n == 1)
		{
			cout << "Base Case.Answer is 1"<<endl;
			return 1;
		}
		else
		{
			factorial = n * fact(n - 1);
			cout << "End of Fact" <<" "<<n;
			cout <<"Answer :"<< factorial << endl;
			return factorial;
			
		}
	}
};
int main()
{
  
	  CalculateFactorial* f=new CalculateFactorial();
	  int result;
	  int value;
	  cout << "Enter the number";
	  cin >> value;
	  result = f->fact(value);
	  cout << "The factorial of" << value << "is " << result << endl;

}*/
/*class FabonacciSeries
{public:
	int sum;
	int calculate_fabonacci(int n)
	{
		cout << "Call To fabonacci"<<endl;
		if (n == 1 || n == 0)
		{
			cout << "Base Case.Answer is 1" << endl;
				return  1;
		}
		else
		{
			sum = calculate_fabonacci(n - 1) + calculate_fabonacci(n - 2);
			cout << "End of call fib" << sum<<endl;
			return sum;
		}

	}
};
int main() 
{
	FabonacciSeries* f = new FabonacciSeries();
	int result;
	int value;
	cout << "Enter the number";
	cin >> value;
	result = f->calculate_fabonacci(value);
	cout << "The fabonacci sum of" << value << "is " << result << endl;
}*/



/*class ARRAY
{public:
	int i = 0;
	int array[5] = {2,4,8,10,6};
	
	int Search(int value)
	{
		cout << "call to search for" << "(" <<value << ")"<<endl;
		int n =sizeof(array)/sizeof(int);
		if (i == n)
		{
			cout << "value not found in array" << endl;
			return 0;
		}
		if (array[i] == value)
		{
			cout << "Base Case"<<endl<<"Value is found at pos";
			cout << i;
			return (i+1);
		}
		else 
		{
			i++;
		   Search(value);
		}
	
	
	}



};
int main()
{	ARRAY* a = new ARRAY();
	int value;
	int result;
	cout << "Find a value in an array";
	cin >> value;
	a->Search(value);
}*/
class ListNode 

{   public:
		int data;
		ListNode* next;
};
class LinkList
{
public:
	ListNode* start;
	ListNode* last;
	ListNode* temp;
	ListNode* loc = last;
	ListNode* ploc;
	//Constructor of link list 
	//creates an empty list
	LinkList()
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
		ListNode* newnode = new ListNode();
		//an object of listNode class iscreated
		newnode->data = value;
		//object of this data part is given value
		if (isEmpty())
		{
			last = newnode;
			start = newnode;
		}
		//if list is empty,After insertion of first element both start and last Pointers point to it.
		else
		{
			newnode->data = value;
			newnode->next = start;
			start = newnode;
			//start pointer is pointed to new node
		}
	}
	
};
	/*void printReverse(ListNode* head)
	{
		cout << "call to function"<< endl;
		// Base case
		if (head == NULL)
		{
			cout << "The List Ends here"<<endl;
			return;
		}
		else {
			// print the list after head node
			printReverse(head->next);
			cout << "function returns for " << head->data<<endl;
		}

		// After everything else is printed, print head
		//cout << head->data << " ";
	}*/
	/*	ListNode* Reverse(ListNode* head)
		{
			cout << "call to function for " <<head->data<< endl;
			// Base case
			if (head==last)
			{
				start = head;
				cout << "The List Ends here" <<head->data<< endl;
				cout << endl;
				return head;
			}

				// print the list after head node
				Reverse(head->next);
				cout << "function returns for"<<head->data<<endl;
				head->next->next = head;
				head->next = NULL;
				last = head;
				return head;

				//cout << "function returns for " << head->data << endl;


		}
		void print()
		{
			temp = start;
			while (temp != NULL)
			{
				cout << temp->data;
				temp = temp->next;

			}


		}

	};
	int main()
	{
		LinkList* a = new LinkList();
		a->insertatFront(5);
		a->insertatFront(4);
		a->insertatFront(3);

		cout <<"Print before reversing"<<endl;
		a->print();
		cout << endl;
		a->Reverse(a->start);
		cout <<endl<< "Print after reversing" << endl;
		a->print();
	}*/
	// A recursive function that  
	   // check a str(s..e) is  
	   // palindrome or not. 
class Palindrome
{public:
	bool isPalindromeRec(char str[], int s, int e)
	{
		//Single character, return true
		if (s == e)
		{
			return true;
		}
		//If first and last characters do not match
		//Return false
		if (str[s] != str[e])
		{
			return false;
		}
		//If they are same, recursion for remaining 
		if (s < e + 1)
		{
			return isPalindromeRec(str, s + 1, e - 1);
		}
		//If it reaches end, return true
		return true;
	}

	bool isPalindrome(char str[])
	{
		int n = strlen(str);
		//empty string is palindrome
		if (n == 0)
		{
			return true;
		}
		//Else, call recursive function
		return isPalindromeRec(str, 0, n - 1);
	}

	
};
int main()
{
		Palindrome* p = new Palindrome();
		char str[] = "racecar";
		if (p->isPalindrome(str))
		{
			cout << "Given input string is palindrome" << endl;;
		}
		else
		{
			cout << "Input string is not palindrome" << endl;
		}
		return 0;
}
ListNode* RecursiveEvenOdd(ListNode* odd, ListNode* even, LinkList* singlyLinkedList2)
{
	//task 7 method to separate the even and odd positioned node.
	//placing the even positioned nodes in reverse order at the front of the main list

	//node to save the previous even node address so that it can be accessed when returned from recursion
	ListNode* evenPre = new ListNode();

	//base case
	if (even->next == NULL)
	{
		singlyLinkedList2->InsertNode(even);
		odd->next = NULL;
		return even;
	}
	else
	{
		//if there are more nodes in the list the even and odd nodes are incremented
		odd->next = even->next;
		odd = even->next;

		if (odd->next == NULL)
		{
			//if there are no more nodes after the odd node.
			singlyLinkedList2->insertatFront(even);
			return even;
		}

		evenPre = even;
		//incrementing the even node.
		even->next = odd->next;
		even = odd->next;
	}

	//even node returned
	ListNode* node = RecursiveEvenOdd(odd, even, singlyLinkedList2);

	singlyLinkedList2->insertatFront(evenPre);

	return node;
}
