#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;


int RandomNumber(int From, int To)
{
	int randnumber = rand() % (To - From + 1) + From;
	return randnumber;
}
void ArrayElement(int arr[100], int& Length)
{
	cout << "enter number of array elements" << endl;
	cin >> Length;

	for (int i = 0; i < Length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
	cout << endl;
}
void CopyArrayInReverseOrder(int arr2[100], int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{

		arr2[i] = arr[Length - 1 - i];

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

	int arr[100], Length;
	int arr2[100];

	ArrayElement(arr, Length);
	cout << "\nArray elements :\n";
	PrintArray(arr, Length);

	CopyArrayInReverseOrder(arr2, arr, Length);
	cout << "\n Reversed array elements :\n";
	PrintArray(arr2, Length);

	return 0;
}