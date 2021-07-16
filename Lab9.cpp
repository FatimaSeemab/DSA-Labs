#include <iostream>
#include <cmath>
#include<chrono>
#include <ctime>
#include <algorithm>
using namespace std;
using namespace std::chrono;
const int max_size =100;
class Sorting
{
public:
	int current = 0;
	int temp = 0;
	int j = 0;
	int middle = 0;
	int min_index = 0;
	//int index = 0;

	bool valswapped = false;
	int i = 0;

	void selectionSort(int array[], int n)
	{

		for (current = i; current <= n - 2; current++)
		{//min index is et to 0 at start of loop
			min_index = current;
			for (j = (current + 1); j <= n - 1; j++)
			{//loop continues from current 
			 //current is boundary between sorted and unsorted part
				if (array[min_index] > array[j])
				{//min index stores the minimum value in unsorted part
					min_index = j;
				}

			}
			//swaps at end of one iteration smallest value with start of unsorted part which is current
			temp = array[current];
			array[current] = array[min_index];
			array[min_index] = temp;
			//printarray(array, n);
		}

	}
	void ShortBubbleSort(int array[], int n)
	{//Algorithm for sorting 

		for (current = 0; current < n; current++)
		{//continues for n no of times
			for (j = 0; j < n - 1; j++)
			{//starts from first element of array and continues till last 
				if (array[j] > array[j + 1])
				{//swaps the elements if value at lower index is greter than its preceding one
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					valswapped = true;

				}
				else
				{//else continues
					continue;
				}

			}

			if (!valswapped)
			{
				break;
			}
			valswapped = false;
		}

	}
	void BubbleSort(int array[], int n)
	{
		//Algorithm for sorting 

		for (current = 0; current < n; current++)
		{//continues for n no of times
			for (j = 0; j < n - 1; j++)
			{//starts from first element of array and continues till last 
				if (array[j] > array[j + 1])
				{//swaps the elements if value at lower index is greter than its preceding one
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					valswapped = true;

				}
				else
				{//else continues
					continue;
				}

			}
			//printarray(array, n);

		}
	}
	void MergeSort(int array[], int first, int last)
	{

		if (first < last)
		{
			int middle = (last + first) / 2;
			MergeSort(array, first, middle);
			MergeSort(array, middle + 1, last);
			Merge(array, first, middle, middle + 1, last);
		}
		else
		{
			return;
		}

	}
	void Merge(int array[], int leftfirst, int leftlast, int rightfirst, int rightlast)
	{

		int temparray[max_size];
		int index = leftfirst;
		int savefirst = leftfirst;

		while ((leftfirst <= leftlast) && (rightfirst <= rightlast))
		{

			if (array[leftfirst] < array[rightfirst])
			{
				temparray[index] = array[leftfirst];

				leftfirst++;
				index++;
			}
			else
			{
				temparray[index] = array[rightfirst];

				rightfirst++;
				index++;

			}
		}
		while (leftfirst <= leftlast)
		{
			temparray[index] = array[leftfirst];
			leftfirst++;
			index++;
		}
		while (rightfirst <= rightlast)
		{

			temparray[index] = array[rightfirst];

			rightfirst++;
			index++;
		}
		for (index = savefirst; index <= rightlast; index++)
		{
			array[index] = temparray[index];
		}
		//printarray(array, 10);
	}
	//Function for printing array
	void printarray(int array[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "  " << array[i];
		}
		cout << endl;
	}
	/*void AlgorithmComparison()
	{
		
		int array100[100];
		int arraycopy100[100];
		int arraycopy1000[1000];
		int arraycopy5000[5000];
		int array1000[1000];
		int array5000[5000];
		for (int i = 0; i < 100; i++)
		{
			array100[i] = 1 + (rand()%1000);

		}
		for (int i = 0; i < 5000; i++)
		{
			array5000[i] = 1 + (rand()%1000);

		}
		for (int i = 0; i < 1000; i++)
		{
			array1000[i] = 1 + (rand()%1000);

		}
		for (int i = 0; i < 1000; i++)
		{
			arraycopy1000[i] = array1000[i];
			
		}
		for (int i = 0; i < 100; i++)
		{
			arraycopy100[i] = array100[i];
			
		}
		for (int i = 0; i < 5000; i++)
		{
			arraycopy5000[i] = array5000[i];
		}
		//printarray(array100, 100);
		//printarray(arraycopy100, 100);
		copyarray100(arraycopy100,array100);
		auto start = high_resolution_clock::now();
		selectionSort(arraycopy100, 100);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by selection sort for size 100 is "<<duration.count() << endl;

		
		copyarray1000(arraycopy1000, array1000);
		start = high_resolution_clock::now();
		selectionSort(arraycopy1000, 1000);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by selection sort for size 1000 is " << duration.count() << endl;

		copyarray1000(arraycopy5000, array5000);
	    start = high_resolution_clock::now();
		selectionSort(arraycopy5000, 5000);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by selection sort for size 5000 is " << duration.count() << endl;


		copyarray100(arraycopy100, array100);
		 start = high_resolution_clock::now();
		BubbleSort(arraycopy100, 100);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by bubble sort for size 100 is " << duration.count() << endl;

		copyarray1000(arraycopy1000, array1000);
		 start = high_resolution_clock::now();
		BubbleSort(arraycopy1000, 1000);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by bubble sort for size 1000 is " << duration.count() << endl;


		copyarray5000(arraycopy5000, array5000);
		start = high_resolution_clock::now();
		BubbleSort(arraycopy5000,5000);
		stop = high_resolution_clock::now();
	 duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by bubble sort for size 5000 is" << duration.count() << endl;

		copyarray100(arraycopy100, array100);
	     start = high_resolution_clock::now();
		ShortBubbleSort(arraycopy100, 100);
		 stop = high_resolution_clock::now();
		 duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by short bubble sort for size 100 is " << duration.count() << endl;

		copyarray1000(arraycopy1000, array1000);
		start = high_resolution_clock::now();
		ShortBubbleSort(arraycopy1000, 1000);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by short bubble sort for size 1000 is " << duration.count() << endl;

		copyarray5000(arraycopy5000, array5000);
		start = high_resolution_clock::now();
		ShortBubbleSort(arraycopy5000, 5000);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by short bubble sort for size 5000 is " << duration.count() << endl;

		/*copyarray100(arraycopy100, array100);
		start = high_resolution_clock::now();
		MergeSort(arraycopy100,0,99);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by merge sort for size 100 is " << duration.count() << endl;*/
		

		/*copyarray1000(arraycopy1000, array1000);
		start = high_resolution_clock::now();
		MergeSort(arraycopy1000, 0, 999);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by merge sort for 1000 is " << duration.count() << endl;*/
		
		/*copyarray5000(arraycopy5000, array5000);
		start = high_resolution_clock::now();
		MergeSort(arraycopy5000, 0, 4999);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by merge sort for 5000 is " << duration.count() << endl;


	}*/
	void copyarray100(int arraycopy100[100],int array100[])
	{
		for (int i = 0; i < 100; i++)
		{
			arraycopy100[i] = array100[i];

		}
	}
	/*void copyarray1000(int arraycopy1000[1000], int array1000[])
	{
		for (int i = 0; i < 1000; i++)
		{
			arraycopy1000[i] = array1000[i];

		}
	}
	void copyarray5000(int arraycopy5000[1000], int array5000[])
	{
		for (int i = 0; i < 5000; i++)
		{
			arraycopy5000[i] = array5000[i];

		}
	}*/
	void sortarray()
	{
		int array[100];
		//int array2[100];
		int arraycopy[100];
		int arraycopydesc[100];
		RandomArrayGenerator(array);
		sort(array, array + 100);
		copyarray100(arraycopy, array);
		sort(array, array + 100, greater<int>());
		copyarray100(arraycopydesc, array);
		
		//printarray(arraycopy, 100);
		//printarray(arraycopydesc, 100);
		
		auto start = high_resolution_clock::now();
		MergeSort(arraycopy, 0, 99);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "best case time complexity by merge sort for size 100 is " << duration.count() << endl;


		start = high_resolution_clock::now();
		MergeSort(arraycopydesc, 0, 99);
		stop = high_resolution_clock::now();
		 duration = duration_cast<microseconds>(stop - start);
		cout << "worst case time complexity by merge sort for size 100 is " << duration.count() << endl;

		copyarray100(arraycopydesc, array);
		start = high_resolution_clock::now();
		selectionSort(arraycopydesc,100);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "worst case complexity for selection sort of size 100 is " << duration.count() << endl;

		//sort(arraycopy, array + 100);
		copyarray100(arraycopydesc, array);
		start = high_resolution_clock::now();
		selectionSort(arraycopy, 100);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "best case complexity for selection sort of size 100 is " << duration.count() << endl;

		
		start = high_resolution_clock::now();
		BubbleSort(arraycopy, 100);
	    stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "best case time complexity for bubble sort for size 100 is " << duration.count() << endl;

		//sort(arraycopy, array + 100);
		copyarray100(arraycopydesc, array);
		start = high_resolution_clock::now();
		BubbleSort(arraycopydesc, 100);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "worst case complexity for Bubble sort of size 100 is " << duration.count() << endl;

		start = high_resolution_clock::now();
		ShortBubbleSort(arraycopy, 100);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "time taken by  short bubble sort for size 100 is " << duration.count() << endl;


		//printarray(arraycopydesc, 100);
		copyarray100(arraycopydesc, array);
		start = high_resolution_clock::now();
		ShortBubbleSort(arraycopydesc, 100);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "worst case complexity  of short bubble sort for size 100 is " << duration.count() << endl;
		
	    
	}
	void RandomArrayGenerator(int array[])
	{
		for (int i = 0; i < 100; i++)
		{
			array[i] = 1 + (rand() % 1000);

		}
	
	
	}

};
int main()
{
	int array[10] = {3,2,1,4,5,6,7,9,12,10};
	Sorting* sort = new Sorting();
	sort->sortarray();
	//sort->ShortBubbleSort(array, 4);
	//sort->MergeSort(array, 0,9);
	//sort->printarray(array, 10);
	//sort->AlgorithmComparison();
	//sort->selectionSort(array, 10);

	

}