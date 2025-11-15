#include<iostream>
#include<cmath>
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
void PrintNumberPattern(int number)
{

	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}
int main()
{

	PrintNumberPattern(readnumbers("enter a positive number"));

	return 0;
}

