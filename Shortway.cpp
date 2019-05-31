// ShortestWay.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class element
{
public:
	int point;
	int distance_to_beginning;
};


int main()
{
	int n, j, input;

	cin >> n;
	vector< vector<int> > Graph;
	for (int i = 0; i < n; i++)
	{
		cin >> j;
		vector<int> A;

		for (; j > 0; j--)
		{
			cin >> input;
			A.push_back(input);
		}
		Graph.push_back(A);
	}

	//test input
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < Graph[i].size(); j++)
		{
			cout << Graph[i][j]<<" ";
		}
		cout << endl;
	}
	//end test input

	//without class
	/*
	int way = 0;
	vector<int> Vert;
	queue<int> vertices;
	Vert.push_back(1);
	
	vertices.push(1);

	while (vertices.empty() == false)
	{
		for (int i = 0; i < Graph[vertices.front() - 1].size(); i++)
		{
			bool is_present = false;
			for (int j = 0; j < Vert.size(); j++)
			{
				if (Graph[vertices.front()- 1][i] == Vert[j])
				{
					is_present = true;
					//cout << "existing" << endl;
				}
			}
			if (is_present == false)
			{
				vertices.push(Graph[vertices.front() - 1][i]);
				Vert.push_back(Graph[vertices.front() - 1][i]);
			}
		}
		
		vertices.pop();
	}
	*/
	//end without class

	//class
	vector<element> way;
	vector<element> Vert;
	queue<element> vertices;
	element *def = new element;
	def->point = 1;
	def->distance_to_beginning = 0;

	Vert.push_back(*def);

	vertices.push(*def);

	while (vertices.empty() == false)
	{
		for (int i = 0; i < Graph[vertices.front().point - 1].size(); i++)
		{
			bool is_present = false;
			for (int j = 0; j < Vert.size(); j++)
			{
				if (Graph[vertices.front().point - 1][i] == Vert[j].point)
				{
					is_present = true;
					//cout << "existing" << endl;
				}
			}
			if (is_present == false)
			{
				element *e = new element;
				e->point = Graph[vertices.front().point - 1][i];
				e->distance_to_beginning = vertices.front().distance_to_beginning + 1;
				vertices.push(*e);
				Vert.push_back(*e);
			}
		}

		vertices.pop();
	}
	//end class

	//test vector
	cout << endl;
	for (int i = 0; i < Vert.size(); i++)
	{
		cout << Vert[i].point << " ";
	}
	cout << endl;
	//end test vector

	cout << "shortest way is: " << Vert[Vert.size() - 1].distance_to_beginning << endl;
    return 0;
}

