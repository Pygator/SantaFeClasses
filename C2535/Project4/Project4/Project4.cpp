// Project4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy
using namespace std;
//...
//vector<int> v;         // no need to prepend std:: any more

void max(vector<int> & v)
{
	int size = v.size();
	int maxAge = 0;
	for (int i = 0; i<size; i++)
	{
		if (maxAge < v[i])
		{
			maxAge = v[i];
		}
	}
	cout << "Max Age: " << maxAge << ' ';
	cout << endl;
}

int main()
{
	//...
	size_t size = 10;
	std::vector<int> array;    // make room for 10 integers,
									 // and initialize them to 0
									 // do something with them:
	array.reserve(10);

	array.push_back(49);
	array.push_back(15);
	array.push_back(23);
	array.push_back(21);
	array.push_back(48);
	// print the deets
	std::cout << array.capacity() << std::endl;
	std::cout << array.size() << std::endl;
	std::cout << array[0] << std::endl;
	std::cout << array[1] << std::endl;
	std::cout << array[2] << std::endl;
	// call a function
	max(array);

	std::ifstream is("Numbers.txt");
	std::istream_iterator<double> start(is), end;
	std::vector<int> numbers(start, end);
	std::cout << "Read " << numbers.size() << " numbers" << std::endl;

	// print the numbers to stdout
	std::cout << "numbers read in:\n";
	std::copy(numbers.begin(), numbers.end(),
	std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	max(numbers);

	// no need to delete anything
    return 0;
}

