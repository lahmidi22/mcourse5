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
void CopyArray1(int arrSource[100], int arrDestination[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		arrDestination[i] = arrSource[i];
	}
}




int main()
{
	srand((unsigned)time(NULL));


	int arr[100];
	int length;

	ArrElement(arr, length);

	int arr2[100];
	CopyArray1(arr, arr2, length);

	cout << "\nArray 1 elements :\n";
	PrintArrElement(arr, length);

	cout << "array 2 elements ater copy :\n";
	PrintArrElement(arr2, length);

	return 0;
}