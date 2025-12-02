#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;


int ReadPositiveNumber(string Message)
{
	short Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int randnumber = rand() % (To - From + 1) + From;
	return randnumber;
}

void FillArray(short  arr[100], short& arrLength)
{

	cout << "enter a number" << endl;
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
	cout << endl;
}
void PrintArrayElement(short arr[100], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

short FindNumberPosition(short Number, short arr[100], short arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{
		if (Number == arr[i])
		{
			return i;
		}

	}
	return -1;
}
bool IsNumberInArray(short Number, short arr[100], short arrLength)
{
	return FindNumberPosition(Number, arr, arrLength) != -1;
}

int main()
{
	srand((unsigned)time(NULL));

	short arr[100], arrLength;
	FillArray(arr, arrLength);
	cout << "arr 1 element : " << endl;
	PrintArrayElement(arr, arrLength);

	short Number = ReadPositiveNumber("Please enter a number to search for?");

	cout << "Number you ar looking for is :" << Number << endl;

	short NumberPosition = FindNumberPosition(Number, arr, arrLength);

	if (!IsNumberInArray(Number, arr, arrLength))
	{
		cout << "No, The number is not found :-(\n";
	}
	else
	{
		cout << "Yes, The number is found :-)";

	}


	return 0;
}