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

int MaxNumber(int arr[100], int length)
{
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{

		if (max < arr[i])
		{
			max = arr[i];
		}

	}
	return max;

}



int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int length;

	ArrElement(arr, length);

	cout << "array element ";
	PrintArrElement(arr, length);

	cout << "max number: ";
	cout << MaxNumber(arr, length);

	return 0;
}