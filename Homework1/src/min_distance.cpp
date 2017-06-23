/*
 * Title: min_distance.cpp
 * Abstract: This program prompts user for 10 integer inputs and calculates the minimum
 * distance in those integers.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 04/22/2017
 */

#include <iostream>
#include <algorithm> // sort()
#include <climits> //INT_MAX
#include <vector>

using namespace std;

const int MAX_SIZE = 10;

/*
 * Calculates least distance and pushes corresponding pairs into array.
 */
void calcMinDistance(vector<int> arr, vector<int> &pairs, int *least)
{
	sort(arr.begin(), arr.end()); //sort array in ascending order

	for (int i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i + 1] - arr[i] < *least && arr[i + 1] - arr[i] > 0)
		{
			pairs.clear();

			*least = arr[i + 1] - arr[i];

			pairs.push_back(arr[i + 1]);
			pairs.push_back(arr[i]);
		}
		else if (arr[i + 1] - arr[i] == *least)
		{
			pairs.push_back(arr[i + 1]);
			pairs.push_back(arr[i]);
		}
	}
}

/*
 * Updates array passed by reference with user input.
 */
void printPrompt(vector<int> &numsArr)
{
	cout << "Enter numbers: ";

	for (int i = 0; i < numsArr.size(); i++)
	{
		cin >> numsArr[i]; //store user input
	}
}

/*
 *
 */
void printAnswers(int least, vector<int> arr)
{
	cout << "Min distance: " << least << endl;

	for (int i = 0; i < arr.size(); i += 2)
	{
		cout << "Two numbers for min distance: " << arr[i] << " and " << arr[i + 1] << endl;
	}
}


//for debugging purposes only
void printArray(vector<int> arr)
{
	cout << "[";

	for (int i = 0; i < arr.size(); i++)
	{
		if (i == arr.size() - 1)
		{
			cout << arr[i] << "]" << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

int main() {
	vector<int> numsArr(MAX_SIZE); //initialize array size 10
	vector<int> pairs;
	int least = INT_MAX;//initialize "least" to infinity

	printPrompt(numsArr);
	calcMinDistance(numsArr, pairs, &least);
	printAnswers(least, pairs);

	return 0;
}

