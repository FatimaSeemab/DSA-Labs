#include <iostream>
using namespace std;
int size_array = 10;
struct DynamicArrayList 
{
    int* pArrayList = new int[size_array];
    int count=0;
	void enteringdata()
	{
		for (int i = 0; i < (size_array); i++)
		{
		  pArrayList[i] = i + 2;
			count++;
		}
	}
	bool isEmpty() 
	{
 
		return pArrayList[0] == 0;
	
	}
	bool isFull()
	{
		if (count == size_array)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void insertAtposition(int value, int position)
	{//check for a value already in list
		DynamicExpansion();
		for (int i = 0; i <= count; i++)
		{
			if (value == pArrayList[i])
			{
				cout << "duplicates in lists are not allowed" << endl;
				return;
			}
		}
		//for valid position
		if ((position > 0) && (position <= size_array))
		{

			for (int i = (count - 1); i >= (position - 1); i--)
			{
				pArrayList[i + 1] = pArrayList[i];
			}
			pArrayList[position - 1] = value;
			count++;
		}

		//for invalid position
		if (position >= size_array)
		{
			cout << "This position is not available";
		}

	}

    void sort_array(int* ArrayList)
	{

		int temp = 0;
		for (int i =0; i < count; i++)
		{

			for (int j = i + 1; j < count; j++)
			{
				if (pArrayList[i] == 0)
				{
					return;
				}
				else{
					if (ArrayList[i] > ArrayList[j])
					{
						temp = ArrayList[i];
						ArrayList[i] = ArrayList[j];
						ArrayList[j] = temp;
					}
				}
			}

		}
		
	}

			
	void insertSorted(int value)
	{
		sort_array(pArrayList);
		if (value == 0)
		{
			cout << "not a valid value" << endl;
			return;
		}
		for (int i = 0; i < size_array; i++)
		{
			if (value == pArrayList[i])
			{
				cout << "already in list" << endl;
				return;
			}
		}
		
		DynamicExpansion();
		for (int i = 0; i < size_array; i++)
		{
			//checks for a value between two numbers in list
			if ((value>pArrayList[i])&&(value < pArrayList[i+1]))
			{
			
				{
					for (int j = (size_array - 1); j > i; j--)
					{
						{

							pArrayList[j] = pArrayList[j - 1];
						}
					}

				}
				
				pArrayList[i+1] = value;
				count++;
				return;
			}
			

		}
		
		 //runs only when value is greater than all numbers in list
			pArrayList[count] = value;
			count++;
			return;
		
	}
    void printList()
	{
		int length = 0;
		for (int i = 0; i < count; i++)
		{
			length = pArrayList[i];
			if (length != NULL)
			{
				cout << pArrayList[i] << endl;
			}

		}
    	cout << endl;
	}

	void DeleteValue(int value) 
	{
		for (int i = 0; i < size_array; i++)
		{
			if (value == pArrayList[i])
			{
				for (i; i <= (size_array - 1); i++)
				{
					if (i == (size_array - 1))
					{
						pArrayList[i] = 0;
						
					}
					else
						pArrayList[i] = pArrayList[i + 1];
					count--;
				}
			}
		}
	
			DynamicReduction();
		
		
    }
	void DeleteValueAtPosition(int pos)
	{
		if ((pos > size_array) || (pos <1))
		{
			cout << "this position is not possible" << endl;
		}
		else
		{
			for (int i = 0; i < size_array; i++)
			{
				if (i == (pos-1))
				{
					for (i; i < (size_array); i++)
					{
						if (i == (size_array - 1))
							pArrayList[i] = 0;
						else
							pArrayList[i] = pArrayList[i + 1];
					}
					count--;
				}
				
			}
			
			
				DynamicReduction();
			
		}

	}
	// deletes a value if a user enters a valid position (1 <= pos <= size of a list)
	void DynamicExpansion() 
	{
		if (count==(size_array--))
		{
			size_array = (2*size_array);
			int* tempArray = NULL;
			tempArray = new int[size_array];
		
			for (int i = 0; i < count; i++)
			{
				tempArray[i] = pArrayList[i];
			
			}
		
			delete[] pArrayList;
			pArrayList = tempArray;
		}

		
	} //Increases size of the array when the list becomes full.
	
		
	void DynamicReduction() 
	{
		if (count < 1 / 2 * (size_array))
		{
			size_array = 1 / 2 * (size_array);
			int* tempArray = NULL;
		
			tempArray = new int[size_array];
			for (int i = 0; i < count; i++)
			{
				tempArray[i] = pArrayList[i];
			}
			delete[] pArrayList;
			pArrayList = tempArray;
			
			
		}

	}
 };

int main()
{

	DynamicArrayList d;
	d.enteringdata();

	cout<< "list is full" << d.isFull() <<endl;
	cout << "list is empty" << d.isEmpty() << endl;
	
	cout << " initially the list members are"  << endl;
	d.printList();

	
	cout << "list after insertion of 8 at 5 " << endl;
	d.insertAtposition(8, 5);
	d.printList();
	cout << "list after deletion of value at 2 position" << endl;
	d.DeleteValueAtPosition(2);
	
	d.printList();
	cout << "list after insertion sorted for 7" << endl;
	d.insertSorted(7);
	d.printList();
	cout << "list after deletion of value at 6" << endl;
	d.DeleteValue(6);

	

	

}


