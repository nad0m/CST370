/*
 * Title: performance.cpp
 * Abstract: This program calculates the performances of selection sort and quicksort.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 6/23/2017
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;


void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int getInputSize()
{
	int size;

	cout << "Enter input size: ";
	cin >> size;

	return size;
}

int getMaxValue()
{
	int max;

	cout << "Enter max value of input: ";
	cin >> max;

	return max;
}

void makeInputFile(int size)
{
	int maxVal = getMaxValue();

	ofstream inputFile ("input.txt");

	for (int i = 0; i < size; i++)
	{
		int n = rand() % (maxVal + 1); // generate random number

		inputFile << n; // store in input file

		if (i != size-1)
		{
			inputFile << " "; // formatting
		}
	}
	inputFile.close();

}

void swap(int &a, int &b, int &counter)
{
	int temp = a;
	a = b;
	b = temp;
	counter++;
}

int selectionSort(int* arr, int size, int &counter)
{
	for (int i = 0; i < size; i++)
	{
		int least = i;

		for (int j = i+1; j < size; j++)
		{
			counter++;
			if (arr[least] > arr[j])
			{
				least = j;
			}
		}

		swap(arr[least], arr[i], counter);
	}


	return counter;
}

void quickSort(int* arr, int left, int right, int &counter)
{
	int i = left;
	int j = right;
	int pivot = arr[left];

	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			counter++;
			i++;
		}
		while (arr[j] > pivot)
		{
			counter++;
			j--;
		}

		if (i <= j)
		{
			swap(arr[i], arr[j], counter);
			i++;
			j--;
		}
	};


	if (left < j)
	  quickSort(arr, left, j, counter);
	if (i < right)
	  quickSort(arr, i, right, counter);

}

int* getData(int size)
{
	int* arr = new int[size];
	int i = 0;
	ifstream file("input.txt");

	while(file.good())
	{
		file >> arr[i];
		i++;
	}

	file.close();

	return arr;
}

void printAnswer(int ss, int qs)
{
	cout << "============================================================" << endl;
	cout << "Generate input data . . ." << endl;
	cout << "Done." << endl;
	cout << "============================================================" << endl;
	cout << "Selection sort performance" << endl;
	cout << "Number of executions: " << ss << " times" << endl;
	cout << "============================================================" << endl;
	cout << "Quicksort performance" << endl;
	cout << "Number of executions: " << qs << " times" << endl;
	cout << "============================================================" << endl;

}

int main() {
	int ssCounter = 0;
	int qsCounter = 0;
	int size = getInputSize();

	makeInputFile(size);

	int* selectionArr =  getData(size);
	int* quickArr = getData(size);


	selectionSort(selectionArr, size, ssCounter); // selection sort

	quickSort(quickArr, 0, size-1, qsCounter); // quicksort


	printAnswer(ssCounter, qsCounter);

	return 0;
}
