#include<iostream>
#include<string> 

using namespace std;


int readnumbers(string Message)
{
	int number = 0;

	do
	{
		cout << Message << endl;
		cin >> number;
	} while (number <= 0);

	return number;

}

void PrintLettersPattern(int number)
{

	for (int i = 65; i <= 65 + number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}



int main()
{

	PrintLettersPattern(readnumbers("enter a positive number"));

	return 0;
}
