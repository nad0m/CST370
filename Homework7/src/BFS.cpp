/*
 * Title: BFS.cpp
 * Abstract: This program implements the breadth-first search algorithm.
 * distance in those integers.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 6/20/2017
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Prompts user for text file name and returns it.
 *
 * @return fileName string
 */
string getFileName()
{
	string fileName;

	cout << "Enter input file name: ";
	cin >> fileName;

	return fileName;
}

int getStartVertex()
{
	int vertex;

	cout << "Enter a start vertex: ";
	cin >> vertex;

	return vertex;
}

vector<int> performBFS(string fileName, int startVertex)
{
	int vertices;
	int currentNode = 0;
	int counter = 0;
	int value;

	vector<int> nodeArr;
	nodeArr.push_back(startVertex);

	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		myfile >> vertices; //First number in text file: number of vertices

		while (myfile.good())
		{
			myfile >> value;

			if (value == 1)
			{
				if (find(nodeArr.begin(), nodeArr.end(), counter) == nodeArr.end())
				{
					nodeArr.push_back(counter);
				}
			}

			if (counter == vertices-1)
			{
				counter = 0;
				currentNode++;
			} else {
				counter++;
			}

		}
		myfile.close();

	}else cout << "Unable to open file";

	return nodeArr;
}

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == arr.size() - 1)
		{
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << " -> ";
		}
	}
}



int main() {
	string fileName = getFileName();
	int startVertex = getStartVertex();

	printArray(performBFS(fileName, startVertex));

	return 0;
}
