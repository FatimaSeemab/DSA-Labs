#include<iostream>
using namespace std;

class ListNode 
{public:
	   int data;
	   ListNode* next;
};
class LinkList 
{public:
	ListNode* start;
	ListNode* last;
	ListNode* loc;
	ListNode* ploc;
	 LinkList()
	{
		start=NULL;
		last = NULL;
	}
	bool isEmpty()
	{

		return (start == nullptr);
	}
	 void insertatFront(int value)
	{
		ListNode* newnode = new ListNode();
		newnode->data = value;

		if (isEmpty())
		{
			last = newnode;
			start = newnode;
		}

		else
		{
			newnode->data = value;
			newnode->next = start;
			start = newnode;
		}
	}//For printing List in reverse order
	 void printListInReverse()
	 {
		 ListNode* temp;
		 ListNode* ptemp;
		 ListNode* xtemp=NULL;
		 //temp and ptemps are initialized
		 temp = start;
		 ptemp = NULL;
		 //Loop returns when whole list is accessed
		do
		 {//stores the previous value
			ptemp = temp;
		 //points to next value
		  temp = temp->next;
		} while (temp != xtemp);
		//xtemps stores the ptemp previous value where the loop breaks
		 xtemp = ptemp;
		 cout << xtemp->data;
	     //temp is again initialized to start
		 temp = start;
		 //loop continues till xtemp reaches to start 
		 while (xtemp != start) 
		 {//loop continues until the value reaches at which the loop breaks
			 while (temp != xtemp)
			 {
				 ptemp = temp;
				 temp = temp->next;

			 }
			 xtemp = ptemp;
			 temp = start;
			 //displays the last accessed element
			 cout << xtemp->data;
		 }
	 }
		void ReversingLinkList()
	 { 
		 ListNode* previous = NULL;
		 ListNode* temp = start;
		 ListNode* iteration = start;
		 ListNode* store_previous=NULL;
		//loop continues until whole list is accessed 
			 while (temp->next!=NULL)
			 {
				 previous = temp;
				 temp = temp->next;
				
			 }
			 //
			 if(temp==last)
			 {
				 start = temp;
			 }
			 //It will store till where the loop terminates
			 store_previous = previous;
			 //temporary is pointed
			 temp->next = previous;
			 //temp is again pointed to start
			 temp =iteration;
			 //loop continues till previous element not equals start
			 while (store_previous != iteration)
			 {
				 while (temp != store_previous)
				 {
					 previous = temp;
					 temp = temp->next;
				 }
				 store_previous = previous;
				 //the pointer is pointed to its previous element
				 //Pointer field changes
				 temp->next = previous;
				 temp = iteration;
			 }
			 //When loop breaks last equals temp
			 if (temp == iteration)
			 {   temp->next=NULL;
				 last = temp;
			 }
		     if (store_previous !=NULL)
		     {
			 store_previous->next=last->next;
			 last = store_previous;
		     }

	 }
	 void Search(int value)
	 {
		 if (isEmpty())
		 {
			 cout << "There is no list to found";
			 return;
		 }
		 loc = start;
		 ploc = NULL;

		 while ((loc != NULL) && (loc->data < value))
		 {

			 if (loc->data == value)
			 {
				 return;
			 }
			 ploc = loc;
			 loc = loc->next;

		 }
		 if ((loc != NULL) && ((loc->data) != value))
		 {
			 loc == NULL;
		 }


	 }
	void printLinkList()

	{
		ListNode* temp;
		//ListNode* newnode = new ListNode();
		if (isEmpty())
		{
			cout << "nothing to show u";
			return;
		}
		temp = start;
		while (temp != last->next)
		{
           cout << temp->data;
			temp = temp->next;
		}
	}
	void OddNumberDeletion() 
	{
		ListNode* temp;
		ListNode* xtemp=start;
		ListNode* ptemp=NULL;

		temp = start;
		//loop continues until whole list is accessed 
		while (temp != NULL) 
		{//checks wether a element is even or odd
			if (((temp->data) % 2) == 0)
			{
				ptemp = temp;
				temp = temp->next;
				//if even pointer points to next field
			}
			else 
			{//xtemp is pointing to the start
				xtemp = temp;
				if (xtemp != NULL)
				{
					if (ptemp != NULL)
					{
						//checks if element is last or not
						if (temp->next == NULL)
						{
							ptemp->next = NULL;
							last = ptemp;
						}
						else
						{//otherwise prtevious points to next of odd number
							ptemp->next = temp->next;
						}

					}
					else
					{
						start = temp->next;
					}
					temp = start;
					//deletes xtemp in case of odd number 
					delete xtemp;

				}
			}
		
		}
		printLinkList();
	}
	void saperate_even()
	{
		ListNode* temp = start;
		ListNode* ptemp_odd=NULL;
		ListNode* ptemp_even=NULL;
		ListNode* temp_odd=NULL;
		ListNode* odd_1 = NULL;
		ListNode* temp_even = NULL;
		ListNode * even_1=NULL;
		//Loop continues until whole list is accessed
		while (temp != NULL)
		{//checks if value is even
			if (((temp->data) % 2) == 0)
			{//if previously even element is found
				if (ptemp_even!=NULL)
				{//initialized to current pointer
					ptemp_even = temp_even;
					ptemp_even->next = temp;
				}
				else 
				{//if previously  no even element is found
				//to store 1st even of list
					even_1 = temp;
					ptemp_even = temp;
				}
				//current is stored
				temp_even = temp;
				//points to next 
				temp = temp->next;

			}
			//checks if value is odd
			else
			{//if previously odd element is found
					if (ptemp_odd!=NULL)
				{
					//initialized to current pointer
					ptemp_odd = temp_odd;
					ptemp_odd->next = temp;
				}
				else 
				{//if previously  no odd element is found
				//to store 1st odd of list
					odd_1 = temp;
					ptemp_odd = temp;
				}
                temp_odd = temp;
				//points to next 
				temp = temp->next;
			}
		}
		//for connection of odd to even if 1st element is odd
		if (((start->data)%2)!=0)
		{
			if ((temp_odd != NULL) && (even_1 != NULL))
			{
				temp_odd->next = even_1;
				temp_even->next = NULL;
				last = temp_even;
			}

		}	//for connection of odd to even if 1st element is even
		else
		{
			if ((temp_even != NULL) && (odd_1 != NULL))
			{
				temp_even->next =odd_1;
				temp_odd->next =NULL;
				last = temp_odd;
			}
		}
		printLinkList();
	}
	void swapping_values(int value1, int value2)

	{
		ListNode* ploc1;
		ListNode* loc1;
		ListNode* ploc2;
		ListNode* loc2;
		ListNode* temp = start;
		//Searches value 1 and 2 in list respectively 
		Search(value1);
		//loc and ploc for values are stored in variables like ploc1,loc1 and same for value2
		ploc1 = ploc;
		loc1 = loc;
		//Returns if one of the value is not present in list
		if (loc1 == NULL)
		{
			cout << value1 << "is not found";
			return;
		}
		Search(value2);
		ploc2 = ploc;
		loc2 = loc;
		if (loc2 == NULL)
		{
			cout << value2 << "is not found";
			return;
		}
		//if user enters same values to be swapped method retuens
		if ((ploc1 == NULL) && (ploc2 == NULL))
		{
			cout << "both are same values not allowed in linklist";
			return;
		}
		//if one is head bode and the other is not last
		if ((ploc1==NULL) && (loc2 != last))
		{
			//if both value are not consecutive
			if (loc1->next != loc2)
			{
				//swaps the pointers
				temp = loc2->next;
				loc2->next = loc1->next;
				loc1->next = temp;
				//start is assigned to the first of list after swapping
				start = loc2;
				// loc1 is pointed by previous of loc2
				ploc2->next = loc1; 
			
			}
			//if both value are consecutive
			else
			{   //temp stores next to value2
				temp = loc2->next;
				//start is assigned to the first of list after swapping
				start = loc2;
				//swaps the pointers
				loc2->next = loc1;
				loc1->next = temp;
			}
		}
		//if none is head bode and none is  last
        if ((ploc1 != NULL) && (loc2 != last))
		{//if both value are not consecutive
			if (loc1->next!= loc2)
			{
				//swaps the pointers
				temp = loc2->next;
				loc2->next = loc1->next;
				loc1->next = temp;

				if (ploc1 != NULL)
				{//connections for rest of list
					ploc1->next = loc2;
					ploc2->next = loc1;
				}
			}
			//if both value are consecutive
			else 
			{//swaps the pointers
				temp = loc2->next;
				loc2->next = loc1;
				loc1->next = temp;
				ploc1->next = loc2;

					
			}
		}
		//if none is head bode and one is  last
		if ((ploc1!=NULL) && (loc2->next==NULL))
		{
			//if both value are not consecutive
			if (loc1->next!=loc2)
			{
			 temp = loc1->next;
			 ploc1->next = loc2;
		     loc2->next = loc1->next;
			 ploc2->next = loc1;
			 //for making value1 the last of list
			 loc1->next = NULL;
			 //updates last pointer 
             last = loc1;

			}
			//if both value are not consecutive
			else
			{
				loc2->next = loc1;
				ploc1->next = loc2;
				//for making value1 the last of list
				loc1->next = NULL;
				//updates last pointer
				last = loc1;
				
				printLinkList();
			}
			
		}

	}
};
int main() 
{
	LinkList* a = new LinkList();
	
	a->insertatFront(5);
	a->insertatFront(4);
	a->insertatFront(3); 
	a->insertatFront(2);
	a->insertatFront(1); 
	a->printLinkList();
	cout << endl;
	a->swapping_values(1,5);
	a->printLinkList();
	cout << endl;

}
