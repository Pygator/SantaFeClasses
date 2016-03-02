// SampleReadFile.cpp : Defines the entry point for the console application.
//
// reading a text file
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>       // std::isdigit
#include <stdlib.h>     /* atoi */
#include <vector>
using namespace std;

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

void min(vector<int> & v)
{
	int size = v.size();
	int minAge = 999;
	for (int i = 0; i<size; i++)
	{
		if (minAge > v[i])
		{
			minAge = v[i];
		}
	}
	cout << "Min Age: " << minAge << ' ';
	cout << endl;
}

int main() {
	string line;
	std::string str;
	std::vector<string> stringArray;
	std::vector<int> numberArray;

	ifstream myfile("minmax.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line << '\n';
			//int c = line.peek();
			if (std::isdigit(line.at(0)) || line.at(0) == '-' )
			{
				int n = atoi(line.c_str());
				//std::cin >> n;
				std::cout << "You entered the number: " << n << '\n';
				numberArray.push_back(n);
			}
			else
			{
			//	std::string str;
				//str = line;
				//std::cin >> str;
				std::cout << "You entered the word: " << line << '\n';
				stringArray.push_back(line);
			}
		}
		myfile.close();
		max(numberArray);
		min(numberArray);
	}

	else cout << "Unable to open file";

	return 0;
}

