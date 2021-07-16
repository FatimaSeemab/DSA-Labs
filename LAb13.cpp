#include<iostream>
using namespace std;
const int asize =5;
class Heap {
public:
	int A[asize];
	int heap_size = 0;
	int temp = 0;
	Heap()
	{
		for (int i = 1; i <= asize; i++)
		{
			A[i] =0;
		}
		heap_size = 0;
	}
	void Insert(int A[], int value)
	{   
		heap_size++;
		A[heap_size] = value;
		if (isFull())
		{
			cout << "heap is full" << endl;
		}
	    maxHeapifylowtoup(A, heap_size);
	}
	
	bool isEmpty()
	{
        if (heap_size == 0)
		{
			return true;
		}
		else { return false; }
	}
	bool isFull()
	{
		if (heap_size == asize)
		{
			return true;
		}
		else { return false; }
	}
	int delMax(int A[])
	{
		int store = A[1];
		for (int i = 1; i <heap_size; i++)
		{
			A[i] = A[i+1];
		}
		maxHeapify(A, 1, heap_size);
		return store;
	}

	int size()
	{
		return heap_size;
	}
	void maxHeapifylowtoup(int A[], int i)
	{
		int largest;
		if (((i/2) >= 1) && (A[i] > A[i/2]))
			{
				largest = i/2;
				int temp = A[i];
				A[i] = A[largest];
				A[largest] = temp;
				maxHeapifylowtoup(A, largest);
		}
		
	}
	void maxHeapify(int A[],int i, int n)
	{   int largest;
	     if (i>=n)
		 {
			 return;
	     }
		 else
		 {
			 if (((2*i) <= n) && (A[i]<A[2*i]))
			 {
				 largest = 2*i;
				 if ((((2*i) + 1) <= n) && A[largest] < A[(2*i + 1)])
				 {
					 largest = (2*i+1);
				 }
				 int temp = A[i];
				 A[i] = A[largest];
				 A[largest] = temp;
				 maxHeapify(A, largest,n);
			 }
		 }
	}
	int Max(int A[])
	{
		return A[1];
	}
	void buildMaxHeap(int A[],int n)
	{   for (int i =n/2;i>= 1;i--)
		{
			maxHeapify(A, i,n);
		}
	}
	void displayHeap(int A[])
	{
		for (int i = 1; i <asize; i++)
		{cout << A[i];}
	}
	void HeapSort(int A[])
	{
		if (heap_size == 0)
		{
			return;
		}
		else
		{
			temp = A[1];
			A[1] = A[heap_size];
			A[heap_size] = temp;
			heap_size--;
			cout << endl;
			cout <<"heap_size: " <<heap_size<<endl;
			maxHeapify(A, 1,heap_size);
			displayHeap(A);
			cout << endl;
			HeapSort(A);

		}
	
	}
};
int main()
{
	Heap* h=new Heap();
	int Array[5];
	h->Insert(Array,4);
	h->Insert(Array, 2);
	h->Insert(Array, 3);
	h->Insert(Array, 1);
	h->HeapSort(Array);
	h->displayHeap(Array);

}