//============================================================================
// Name        : Homework6.cpp
// Author      : Huy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int getNum()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	return n;
}

int power(int n)
{
	n--;

	if (n == -1)
	{
		return 1;
	}
	return 2*power(n);
}

void printResult(int result)
{
	cout << "Result: " << result;
}


int main() {

	printResult(power(getNum()));

	return 0;
}
