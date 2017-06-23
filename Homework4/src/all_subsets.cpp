/*
 * Title: all_subsets.cpp
 * Abstract: This program displays all subsets of a set.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 05/19/2017
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_BINARY_DIGITS = 15; // max number of binary digits

/*
 * Prompts user for integer and returns it.
 *
 * @return n
 */
int getNum()
{
	int n;
	cout << "Number of input characters: ";
	cin >> n;

	return n;
}

vector<char> getChars(int n)
{
	vector<char> arr(n);

	cout << "Enter "<< n << " character(s): ";

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i]; //store user input
	}

	return arr;
}


void printArray(vector<char> arr)
{
	cout << "{";

	for (int i = 0; i < arr.size(); i++)
	{
		if (i == arr.size() - 1)
		{
			cout << arr[i] << "}" << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

int getSubsetAmount(int n)
{
	return pow(2, n) - 1;
}


void printSubsets(vector<char> arr)
{
	int m = getSubsetAmount(arr.size());
	int binDigits = arr.size(); // max size of each subset
	vector<char> subset;

	cout << "===== All Subsets =====" << endl;

	for (int i = 0; i <= m; i++)
	{
		bitset<MAX_BINARY_DIGITS> binValue = bitset<MAX_BINARY_DIGITS>(i); // bitset index starts from least
																		   // significant digit

		for (int j = 0; j < binDigits; j++)
		{
			if (binValue[j] == 1)
			{
				subset.push_back(arr[j]);
			}
		}

		if (subset.size() == 0)
		{
			cout << "empty" << endl;
		}else{
			printArray(subset);
			subset.clear();
		}
	}
}

int main() {

	printSubsets(getChars(getNum()));

	return 0;
}

