#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;

int ReadPositiveNumber(string Message)
{
	int number = 0;
	do
	{
		cout << Message << endl;
		cin >> number;

	} while (number < 0);
	return number;
}

void Swap(int& A, int& B)
{
	int swap = 0;
	swap = A;
	A = B;
	B = swap;

}

int RandomNumber(int From, int To)
{
	int randnumber = rand() % (To - From + 1) + From;
	return randnumber;
}
void ArrayElement(int arr[100], int& Length)
{
	for (int i = 0; i < Length; i++)
	{
		arr[i] = i + 1;
	}
}
void ShuffleArray(int arr[100], int Length)
{
	for (int i = 1; i < Length; i++)
	{
		Swap(arr[RandomNumber(1, Length) - 1], arr[RandomNumber(1, Length) - 1]);
	}
}

void PrintArray(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Length = ReadPositiveNumber("Enter number of elements :");

	int arr[100];

	ArrayElement(arr, Length);
	cout << "\nArray elements :\n";
	PrintArray(arr, Length);

	ShuffleArray(arr, Length);
	cout << "\nArray elements after shuffle:\n";
	PrintArray(arr, Length);




	return 0;
}