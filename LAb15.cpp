#include<iostream>
using namespace std;
class G {
public:
	int data=0;
	int p=0;
	int k=0;
};
class PrimsAlgo {
   public:
	   int smallest=0;
   void insert(int array[10][10], int v1, int v2, int weight)
	{
	array[v1][v2] = weight;
	array[v2][v1] = weight;
    }
   bool isconnected(int array[10][10], int v1, int v2)
	{
			if (array[v1][v2] != 0)
			{
				return true;
			}
			else
			{		
				return false;
			}


	}
   void  PrintGraph(int array[10][10])
	{
		for (int i = 1; i < 10; i++)
		{
			cout << "members of vertex" << i << endl;
				for (int j = 1; j < 10; j++)
				{   
					cout << array[i][j];
				}
				cout << endl;
		}
	}
   void MST(int array[10][10],int s)
   {
   
 
   
   
   
   }
   void minHeapifylowtoup(G* A[], int i)
   {

	   if (((i/2) >= 1) && (A[i]<A[i/2]))
	   {
		   smallest = i;
		   int temp = A[i/2]->data;
		   A[i/2]->data = A[smallest]->data;
		   A[smallest]->data = temp;
		   for (int i = 0; i < 10; i++)
		   {
			   cout<<A[i]->data;
		   }
		   cout << endl;
		   minHeapifylowtoup(A, i/2);
	   }

   }
   void BuildMinHeap(G* A[], int n)
   { for (int i = n; i >= 1; i--)
	 {minHeapifylowtoup(A, i);}
   }
	};
	int main()
	{
		int n;
		bool directed = false;
		G* primarray[10];
		for (int i = 0; i < 10; i++)
		{
			primarray[i] = new G();
			primarray[i]->data = 10-i;
		}
		
		
		int array[10][10] = { {0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} ,
		 {0,0,0,0,0,0,0,0,0,0} };

		PrimsAlgo* p = new PrimsAlgo();
		p->insert(array, 1, 2, 4);
		p->insert(array, 1, 4, 1);
		p->insert(array, 1, 5, 8);
		p->insert(array, 2, 3, 2);
		p->insert(array, 2, 4, 2);
		p->insert(array, 2, 5, 6);
		p->insert(array, 2, 6, 1);
		p->insert(array, 3, 5, 2);
		p->insert(array, 3, 6, 5);
		p->insert(array, 4, 5, 11);
		p->insert(array, 4, 7, 9);
		p->insert(array, 4, 8, 8);
		p->insert(array, 5, 6, 3);
		p->insert(array, 5, 7, 4);
		p->insert(array, 5, 8, 1);
		p->insert(array, 5, 9, 5);
		p->insert(array, 6, 8, 7);
		p->insert(array, 6, 9, 8);
		p->insert(array, 7, 8, 1);
		p->insert(array, 8, 9, 3);
		p->PrintGraph(array);
		for (int i = 0; i < 10; i++)
		{
			cout << primarray[i]->data << endl;
		}
		p->BuildMinHeap(primarray, 10);
		cout << endl;
		for (int i = 1; i < 10; i++)
		{
			cout<<primarray[i]->data<<endl;
		}
		//cout << g->isconnected(array, 1, 3);
	}

