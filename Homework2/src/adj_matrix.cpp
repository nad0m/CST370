/*
 * Title: adj_matrix.cpp
 * Abstract: This program converts a directed graph stored in
 * 			 an input file into an adjacency matrix format.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 04/28/2017
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

/*
 * Takes in number of vertices and edges as input and prints to screen.
 *
 * @param vertices
 * @param edges
 */
void printAnswers(int vertices, int edges)
{
	cout << "Number of vertices: " << vertices << endl;
	cout << "Number of edges: " << edges << endl;
}

/*
 * Creates an empty 2D vector array containing all 0s.
 *
 * @param n vertices
 * @return matrix
 */
vector<vector<int> > createEmptyMatrix(int n)
{
	vector<int> row(n, 0);//create first row in 2D array filled with 0s
	vector<vector<int> > matrix(n, row); //duplicate row n times (vector of vectors)

	return matrix;
}

/*
 * Reads in file name returned by getFileName() and dynamically creates
 * matrix based on file content.
 *
 * @return final matrix
 */
vector<vector<int> > generateAdjMatrix()
{
	int v;
	int e;
	int row;
	int col;
	vector<vector<int> > matrix;

	ifstream myfile(getFileName());

		if (myfile.is_open())
		{
			myfile >> v; //number of vertices
			myfile >> e; //number of edges

			printAnswers(v, e);

			matrix = createEmptyMatrix(v); //create a matrix based on *v value

			while (myfile.good())
			{
				myfile >> row;
				myfile >> col;

				matrix[row][col] = 1; //assign edge
			}
			myfile.close();

		}else cout << "Unable to open file";

		return matrix;
}

/*
 * Prints entire 2D array matrix to screen.
 *
 * @param arr
 */
void printMatrix(vector<vector<int> > arr)
{
	cout << "Adjacency matrix: " << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		cout << "  "; //formatting

		for (int j = 0; j < arr.size(); j++)
		{
			cout <<arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	printMatrix(generateAdjMatrix());

	return 0;
}
