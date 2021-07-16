# include <iostream>
using namespace std;
//A structure of ListNode is created
struct ListNode
{//declares two datafields data and next pointer both are public
public:
	int data;
	ListNode* next;

};
class LinkList
{//ListNode objects last,loc and ploc are created
public: ListNode* last;
	  ListNode* loc;
	  ListNode* ploc;
	  //A constructor to initialize linklist
	  LinkList() 
	  {
		  last = NULL;
		  ploc = NULL; 
		  loc = NULL;
	  }
	  //A method to return whether list is empty or not
	 bool isEmpty() 
	  {
		  return (last== NULL);
	  }
	 //Method to insert value at front 
	 void InsertAtFront(int value) 
	 {//A listNode object is created
		 ListNode* node = new ListNode();
		 //List empty is call to check whether isertion would bhe in emptyList
		 if (isEmpty())
		 {//node next points to itself bcz it is circular list
			 node->next = node;
			 last = node;
			 ///last is also pointed to this only node
		 }
		 else 
		 {
			 //node next is pointed to element after start
			 node->next = last->next;
			 //in other words start is updated as insertion is at front of list
			 last->next = node;
		 }
		 node->data = value;
		 //value is inserted in its data part
	 }
	 void InsertAtLast(int value) 
	 {////A listNode object is created
		 ListNode* node = new ListNode();
		 //List empty is call to check whether isertion would bhe in emptyList
		 if (isEmpty())
		 {
			 //node next points to itself bcz it is circular list
			 node->next = node;
			 last = node;
			 //last is also pointed to this only node
		 }
		 else
		 { //node next is pointed to element after start
			 node->next = last->next;
			 last->next = node;
			 //Last is updated
			 last = node;
			
		 }
		 node->data = value;
		 //value is inserted in its data part
	 }
	 void PrintList()
	 { 
		 if (!isEmpty()) {
			 //temp pointer is declared to iterate over the whole list
			 //initially pointed to first element
			 ListNode* temp = last->next;
			 do {//prints data in list
				 
					 cout << " " << temp->data;
					 //temp is incremneted
					 temp = temp->next;
				 
			 } while (temp != last->next);
			 //loop continues till the whole list is printed
			 cout << endl;

		 }
		 else
		 {
			 cout << "List is  Empty";
		 }
		 cout << endl;
	 }
	 void SearchValue(int value) 
	 {
		 loc = NULL;
		 ploc = NULL;
		 if (isEmpty()) { cout << "no value in list to search"; }
		 else {
			 //loca nd ploc areinitialized to last and first elemnet in list
			 loc = last->next; ploc = last;
			 //loop iterates the whole list and loc value should not be gretaer than its value
			 while ((loc!=last) && (loc->data<value))
			 {//ploc is pointed to previous of loc
				 ploc = loc;
				 //loc is pointed to next
				 loc = loc->next;
				 //value is found
				 if (value == loc->data)
					 //method returns
					 return;
			 }
			 if (loc->data!=value)
			 {//when value is not found
				 if (value>(loc->data)&&(loc==last))
				 {//value is greater than loc data
					 ploc = last;
					
				 }
				 //loc makes null to show value not found
				 loc = NULL;	
			 }
		 }
	 }
	 //A method  to insert value 
	 void InsertSorted(int value)
	 {//search is call to update loc and ploc
		 SearchValue(value);
		 //loc not equals Null shows value is found in list
		 if (loc != NULL) 
		 {
			 cout << "value is already in list";
			 return;
		 }
		 else {
			 //if not found and list is empty, insert value at front
			 if (isEmpty())
			 {
				 InsertAtFront(value);
				 return;
			 }
			 else
			 {//if ploc points to last insert value at end
				 if (ploc==last) {
					 InsertAtLast(value);
					 return;
				 }

				 else {
					 //if list is not empty or value logical position is not at last
					 //new node creted
					 ListNode* node = new ListNode();
					 ListNode* temp;
					 //temp contains the next of ploc
					 temp = ploc->next;
					 //node is inserted after ploc
					 ploc->next =node;
					 //ploc next address is assigned to next 
					 node->next = temp;
					 node->data = value;
				 }
				 PrintList();
			 }
		 }

	 }
	 //A  method to delete value
	 void DeleteValue(int value) {
		 ///search is call to update loc and ploc
		 SearchValue(value);
		 //Method returns if list is empty
		 if (isEmpty())
		 {
			 cout << "no value in list to delete";
			 return;
		 }
		 else {
			 //condition for deletion of only element
			 if (last->next == last) { last = NULL; }
			 //condition for deletion of last element
			 else if (last->data == value) 
			 {
				 ploc->next = last->next;
				 last = ploc;
			 }
			 //condition for deletion of element in somewher mid
			 else {
			
				 ploc->next = loc->next;
				 delete loc;
			 }

		 }
	 }
	 //Method  to DestroyList
	 void DestroyList()
	 {//A temp pointed to satrt of its list
			 ListNode* temp = last->next;
			 //loop continues over whole list
			 while (last->next != last) {
				 //temp points to start of list
				 temp = last->next;
				 //last next contains the address of its next
				 last->next = last->next->next;
				 //start is deleted
				 delete temp;
				
			 }
			 
			 delete last; //delete the only remaining node
			 last = NULL;
	 }

	 
};
int main() 
{
	LinkList* a = new LinkList();
	a->isEmpty();
	a->InsertAtFront(8);
	a->InsertAtFront(5);
	a->InsertAtLast(10);
	a->InsertSorted(7);
	a->PrintList();
	a->DeleteValue(10);
	a->DestroyList();
	a->PrintList();
}