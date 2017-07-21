//============================================================================
// Name        : Homework11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int getInputSize()
{
	int size;

	cout << "Input size: ";
	cin >> size;

	return size;
}

int* enterNumbers(int size)
{
	int* heap = new int[size];

	cout << "Enter numbers: ";

	for (int i = 1; i < size; i++)
	{
		cin >> heap[i];
	}

	return heap;
}


void printHeap(int* heap, int size)
{
	for (int i = 1; i < size; i++)
	{
		cout << heap[i] << " ";
	}

	cout << endl;
}

bool isHeap (int* heap, int size)
{
	int halfOfHeap = size/2;

	if (size%2 == 1)
	{
		halfOfHeap = size/2+1;
	}

	for (int i = 1; i < halfOfHeap; i++)
	{
		if (heap[2*i] > heap[i] || heap[2*i+1] > heap[i]) // if children greater than parent, return false
		{
			return false;
		}

	}

	return true;
}

void swap (int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* constructHeap(int* heap, int size)
{
	int halfOfHeap = size/2;

	if (size%2 == 1)
	{
		halfOfHeap = size/2+1;
	}

	for (int i = 1; i < halfOfHeap; i++)
	{
		if (heap[2*i] > heap[i]) // child 1
		{
			swap(heap[i], heap[2*i]);
		}
		if (heap[2*i+1] > heap[i]) // child 2
		{
			swap(heap[i], heap[2*i+1]);
		}
	}
	return heap;
}

int* insertValue(int* heap, int* size)
{
	*size = *size+1;
	int* newHeap = new int[*size];

	for (int i = 1; i < *size-1; i++)
	{
		newHeap[i] = heap[i];
	}

	delete [] heap;

	cout << "Enter a number: ";
	cin >> newHeap[*size-1];

	while (!isHeap(newHeap, *size))
	{
		newHeap = constructHeap(newHeap, *size);
	}

	return newHeap;
}

int* deleteMax(int* heap, int* size)
{
	*size = *size-1;
	int* newHeap = new int[*size];

	for(int i = 2; i < *size+1; i++)
	{
		newHeap[i-1] = heap[i];
	}

	delete [] heap;

	while (!isHeap(newHeap, *size))
	{
		newHeap = constructHeap(newHeap, *size);
	}

	return newHeap;
}

void heapSort(int* heap, int size)
{
	cout << "Heap sort: ";
	while(size > 1)
	{
		cout << heap[1] << " ";
		heap = deleteMax(heap, &size);
	}
	cout << endl;

}

void selectOperation(int* heap, int size)
{
	int choice;

	cout << "Select an operation" << endl;
	cout << "	1. Insert a number" << endl;
	cout << "	2. Delete the max" << endl;
	cout << "	3. Heapsort & Quit" << endl;
	cin >> choice;

	switch (choice){
		case 1:
			heap = insertValue(heap, &size);
			cout << "Updated heap: ";
			printHeap(heap, size);
			selectOperation(heap, size);
			break;
		case 2:
			heap = deleteMax(heap, &size);
			cout << "Updated heap: ";
			printHeap(heap, size);
			selectOperation(heap, size);
			break;
		case 3:
			heapSort(heap, size);
			cout << "Bye!";
			break;
	}
}


int* determineHeap(int* heap, int size)
{
	if (isHeap(heap, size))
	{
		cout << "This is a heap." << endl;
	} else {
		cout << "This is NOT a heap." << endl;

		heap = constructHeap(heap, size);

		while (!isHeap(heap, size))
		{
			heap = constructHeap(heap, size);
		}
		cout << "Heap constructed: ";
		printHeap(heap, size);
	}

	return heap;
}

int main() {
	int size = getInputSize()+1; // +1 for simplicity
	int* heap = enterNumbers(size);
	heap = determineHeap(heap, size);
	selectOperation(heap, size);
	return 0;
}
