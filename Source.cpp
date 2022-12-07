#include "qveve.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int ch = 1;
	while (ch == 1)
	{
		cout << ("enter 1 to start, 0 to close >");
		cin >> ch;
		switch (ch)
		{
		case(0):
			break;
		case(1):
		{
			ifstream file;
			file.open("input.txt");
			string input;

			getline(file, input);
			file.close();

			clear(input);
			cout << endl;
			continue;
		}
		default:
		{
			cout << endl << "invalid input error" << endl;
			ch = 1;
		}
		}
	}
}