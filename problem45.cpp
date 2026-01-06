#include<iostream>
#include<string> 
using namespace std;

int  randNumber(int From, int To)
{
	int randomNumber = 0;

	randomNumber = rand() % (To - From + 1) + From;
	return randomNumber;
}

void FillArray(int arr[100], int& arrLength)
{
	cout << "Enter number of elements ?" << endl;
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = randNumber(-100, 100);
	}
}
int CountNegative(int arr[100], int arrLength)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < 0)
		{
			counter++;
		}
	}
	return counter;
}
void PrintArrayElement(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	FillArray(arr, arrLength);

	cout << "\narray 1 elements:\n";
	PrintArrayElement(arr, arrLength);

	cout << "\nNegative Numbers count is : " <<
		CountNegative(arr, arrLength) << endl;

	return 0;
}