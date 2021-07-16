#include <iostream>
#include<chrono>
#include <ctime>
#include <algorithm>
using namespace std;
using namespace std::chrono;

class QuickSort {
public:
	int i = 0;
	int partition(int array[], int left, int right)
	{
		int pivot;
		/*int middle = (left+right)/2;
		if (array[left] < array[middle] )
		{
			if (array[right] > array[middle])
			{
				pivot = middle;
			}
			else
			{
				if (array[left] >= array[right])
					pivot = left;
				else
					pivot = right;
			}
		}
		else 
		{
			if (array[right] < array[middle])
			{
				pivot = middle;
			}
			else
			{
				if (array[left] <= array[right])
					pivot = left;
				else
					pivot = right;
			}
	
		}

		cout <<"left: "<<array[left] <<" right: "<<array[right] <<" middle: "<<array[middle]<<" pivot: "<<pivot<< endl;*/
		pivot =left;
		while (left<=right)
		{
			
			while (array[left]<=array[pivot] &&left<=right)
			{
				left++;
			}

			while (array[right] > array[pivot] && left<=right)
			{
				right--;
			}
			if (left < right)
			{
				int temp;
				temp = array[left];
				array[left] = array[right];
				array[right] = temp;
				
				left++;
				right--;
				
				
			}
	
		}
		int temp2;
		temp2 = array[pivot];
		array[pivot] = array[right];
		array[right] = temp2;
		i++;
		//cout <<"no of partitions made are"<< i<<endl;
		//cout << "return from partition" << endl;
		return right;
	}
	void QuickSortAlgorithm(int A[],int left,int right)
	{
		//cout << "call to QuickSort left " << left << " right  " << right << endl;
		if (left <= right)
		{
			int pivot_index=0;
		    pivot_index=partition(A,left,right);
			
			//cout << "pivot_index" << pivot_index << endl;
			//printArray(A, 9);
			if (pivot_index > 1)
			{
				QuickSortAlgorithm(A, left, pivot_index-1);
			
			}
			if (pivot_index+1<right)
			{
				
				QuickSortAlgorithm(A, pivot_index + 1, right);
			
			}
			

		}
		else {
			//cout << endl << "no of partitions made are " << i << endl;
			return; 

		}
		//cout << "Return from Quick Sort" << endl;
		
	}
	void printArray(int array[], int n)
	{
		for (int i = 0; i <=n; i++)
		{
			cout << array[i] << "  ";
				
		}
		cout<<endl;
	
	
	}

};
/*int main()
{
	int  array[100];
	for (int i = 0; i <100; i++)
	{
		array[i] = 1+rand()%1000;
	}

	QuickSort* a = new QuickSort();
	
	//cout << "array before sorting algorithm is applied" << endl;
	
	//a->printArray(array, 999);
	auto start = high_resolution_clock::now();
	a->QuickSortAlgorithm(array, 0, 99);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl<<"time taken by quick sort for size 100 is " << duration.count() << endl;

	cout << endl << "no of partitions made are " << a->i << endl;

}*/
int main()
{
	int  array[5000];
	for (int i = 0; i < 5000; i++)
	{
		array[i] = 1 + rand() % 1000;
	}

	QuickSort* a = new QuickSort();

	
	auto start = high_resolution_clock::now();
	a->QuickSortAlgorithm(array, 0, 4999);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	cout << endl << "time taken by quick sort for size 5000 is " << duration.count() << endl;
	//cout << endl << "no of partitions made are " << a->i << endl;

}
