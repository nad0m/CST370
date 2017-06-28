/*
 * Title: ts.cpp
 * Abstract: This program implements the topological sort algorithm.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 6/29/2017
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph
{
	int V;

	list<int> *adj;

	void util(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V);

	void addEdge(int v, int w);

	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::util(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
		{
			util(*i, visited, Stack);
		}
	}
	Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			util(i, visited, Stack);
		}
	}

	cout << "Topological sort: ";

	while (!Stack.empty())
	{
		cout << Stack.top();

		Stack.pop();

		if(!Stack.empty())
		{
			cout <<" -> ";
		}
	}
}

string getFileName()
{
	string fileName;

	cout << "Enter filename: ";
	cin >> fileName;

	return fileName;
}

void ts(string fileName)
{
	int vertices;
	int value;
	int row = 0;
	int counter = 0;

	vector<vector<int> > nodeArr;

	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		myfile >> vertices; //First number in text file: number of vertices
		Graph graph(vertices);

		while (myfile.good())
		{
			if (counter == vertices)
			{
				counter = 0;
				row++;
			}

			myfile >> value;

			if (value == 1)
			{
				graph.addEdge(row, counter);
			}
			counter++;

		}
		myfile.close();

		graph.topologicalSort();

	} else cout << "Unable to open file";


}

int main() {

	ts(getFileName());
	return 0;
}
