#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}


enPrimNotPrime CheckPrime(int Number)
{

	int M = round(Number / 2);


	for (int Counter = 2; Counter <= M; Counter++)
	{

		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;


		return enPrimNotPrime::Prime;
	}
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



void CopyOnlyPrimeNumber(int arrSource[100], int arrDestination[100], int length, int& arr2Length)
{
	int counter = 0;

	for (int i = 0; i < length; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
		{
			arrDestination[counter] = arrSource[i];
			counter++;
		}
	}
	arr2Length = counter;
}

void PrintArrElement(int arr[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}




int main()
{
	srand((unsigned)time(NULL));


	int arr[100];
	int length;

	ArrElement(arr, length);

	int arr2[100], arr2Length;
	CopyOnlyPrimeNumber(arr, arr2, length, arr2Length);

	cout << "\nArray 1 elements :\n";
	PrintArrElement(arr, length);

	cout << "\nPrime number in array 2 :\n";
	PrintArrElement(arr2, arr2Length);

	return 0;
}