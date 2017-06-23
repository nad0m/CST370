/*
 * Title: sieve.cpp
 * Abstract: This program takes in an integer as user input and displays all the prime numbers
 * 			 from 2 thru n, including n if it is prime.
 * Author: Huy Nguyen
 * ID: 9419
 * Date: 05/4/2017
 */

#include <iostream>
#include <cmath>
using namespace std;


void printArray(int* arr, int size)
{
	cout << "Prime numbers: ";

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			cout << arr[i] << endl;
		}
		else {
			cout << arr[i] << ", ";
		}
	}
}

/*
 * Takes in an integer and returns an array of primes leading up to that integer.
 *
 * @param n
 * @param *size
 *
 * @return primes
 */
int* sieve(int n, int* size)
{
	int* arr = new int[n];   // allocate arr to size n
	int zeroCounter = 1; // initialize zero counter in arr

	for (int p = 2; p <= n; p++)
	{
		arr[p] = p;
	}

	for (int p = 2; p <= floor(sqrt(n)); p++)
	{
		if (arr[p] != 0)
		{
			int j = p * p;

			while (j <= n)
			{
				if (arr[j] != 0)
				{
					zeroCounter++; // count the number of non-prime numbers
				}
				arr[j] = 0;
				j = j + p;
			}
		}
	}

	*size = n - zeroCounter; // size of the prime array
	int i = 0;
	int* primes = new int[*size]; // allocate prime array to given size

	for (int p = 2; p <= n; p++)
	{
		if (arr[p] != 0)
		{
			primes[i] = arr[p];
			i++;
		}
	}

	delete[] arr;// frees the memory which was previously allocated
	arr = nullptr;//set pointer to null

	return primes;
}

/*
 * Prompts user for integer and returns it.
 *
 * @return n
 */
int promptUser()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	return n;
}

int main(){

	int size;
	int* primes = sieve(promptUser(), &size);

	printArray(primes, size);

	return 0;
}
