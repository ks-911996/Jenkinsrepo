/**********************************************************************
Reimplement a version of the JavaScript function parseInt from scratch 
***********************************************************************/
#include <string>
#include <iostream>
using namespace std;
int parseInt(const string& str);
bool NaN=false; //global variale to check Nan
int parseInt(const string& str)
{
	if (str.empty())
	{
		return 0;
	}

	int radix = 10;
	if (str.length() >= 2 && str[0] == '0' && str[1] == 'x')
		radix = 16;

	size_t start = str.find_first_not_of(' ');

	if (start == string::npos || !isdigit(str[start])) {
		NaN = true;
		return 0;
	}

	string numberstring = str.substr(start);

	//cout <<"numberstring: "<< numberstring << endl;
	try
	{
		size_t position;
		int result = stoi(numberstring,&position, radix);
		if (position != numberstring.length())
		{
			NaN = true;
			return 0;
		}
		return result;
	}
	catch (...) {
		NaN = true;
		return 0;
	}
}

int main()
{
	string inputString;
	cout << "Enter the input: ";
	cin >> inputString;
	int number = parseInt(inputString);
	if (!NaN)
		cout << "The output: " << number << endl;
	else
		cout << "Not a number" << endl;

	inputString.clear();
	return 0;
}