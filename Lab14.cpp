#include<iostream>
using namespace std;
int array[5][5];
class Graph
{public:
	
	void insert(int array[5][5],int v1, int v2, int weight)
	{
		array[v1][v2] =weight;	
		array[v2][v2] = weight;

	}
	void insertdirected(int array[5][5], int v1, int v2, int weight)
	{
		array[v1][v2] = weight;
		

	}
	bool isconnected(int array[5][5], int v1, int v2)
	{
		bool connection = false;
		if (array[v1][v2] != 0)
		{
			return true;
		}
		else 
		{
			int save = v2;

			int savev1 = v1;
			//for (v1 = v1; v1 < 5; v1++)
			do
			{ connection = false;
				for (v2 = 0; v2 < 5; v2++)
				{
					if (array[v1][v2] != 0)
					{
						connection = true;
						if (v2 == save)
						{
							cout << "reached there" << endl;
							return true;
						}
						v1 = v2;
						cout << v1<<endl;
						
						break;
						
					}

				}
				if (!connection)
				{
					cout << "here it goes";
					return false;
				}

			} while (v1 != savev1);
		return false;
		}
	
	
	}
	void  PrintGraph(int array[5][5])
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0;j < 5; j++)
			{
				cout << array[i][j];
			}
			cout << endl;
		}
	}

};
int main()
{
	int n;
	bool directed=false;
	cout << " Is the graph directed?";
	cin >> directed;
	
	int array[5][5] = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };

	Graph* g = new Graph();
	if (directed)
	{
		g->insertdirected(array, 0, 1, 1);
		g->insertdirected(array, 0, 3, 1);
		g->insertdirected(array, 1, 4, 1);
		g->insertdirected(array, 4, 2, 1);
	}
	else
	{
		g->insert(array, 0, 1, 1);
		g->insert(array, 0, 3, 1);
		g->insert(array, 1, 4, 1);
		g->insert(array, 4, 2, 1);
	}
	g->PrintGraph(array);
	cout<<g->isconnected(array, 1, 3);
}