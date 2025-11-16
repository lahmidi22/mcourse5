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

void PrintInvertedLettersPattern(int number)
{
	for (int i = 65 + number - 1; i >= 65; i--)
	{
		for (int j = 1; j <= number - (65 + number - 1 - i); j++)
		{
			cout << char(i);
		}
		cout << "\n";
	}
}



int main()
{

	PrintInvertedLettersPattern(readnumbers("enter a positive number"));

	return 0;
}
