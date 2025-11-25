#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

void ArrElement(int arr[100], int& length)
{
	cout << "enter numbr of element" << endl;
	cin >> length;

	for (int i = 0; i < length; i++)
	{

		arr[i] = RandomNumber(1, 100);

	}

}

void PrintArrElement(int arr[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int sumNumber(int arr[100], int length)
{
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += arr[i];

	}
	return sum;

}

float AverageNumber(int arr[100], int length)
{
	return (float)sumNumber(arr, length) / length;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int length;

	ArrElement(arr, length);

	cout << "\nArray elements ";
	PrintArrElement(arr, length);

	cout << "\nAverage number : ";
	cout << AverageNumber(arr, length);

	return 0;
}