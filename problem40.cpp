#include<iostream>
#include<string> 
using namespace std;



void FillArray(int arr[100], int& arrLength)
{
	arrLength = 10;

	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;


}
short FindNumberPositionInArray(int number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == number)
		{
			return i;
		}

	}
	return -1;
}

bool IsNumberInArray(int number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(number, arr, arrLength) != -1;
}

void AddAraayElement(int number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = number;

}

void CopyDistinctNumbersToArray(int arr[100], int arr2[100], int arrLength, int& arr2Length)
{

	for (int i = 0; i < arrLength; i++)
	{

		if (!IsNumberInArray(arr[i], arr2, arr2Length))
		{
			AddAraayElement(arr[i], arr2, arr2Length);
		}

	}

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

	int arr[100], arrLength = 0;
	int arr2[100], arr2Length = 0;

	FillArray(arr, arrLength);

	cout << "\narray 1 elements : \n" << endl;
	PrintArrayElement(arr, arrLength);

	CopyDistinctNumbersToArray(arr, arr2, arrLength, arr2Length);


	cout << "\narray 2  after copy distinct numbers : \n" << endl;
	PrintArrayElement(arr2, arrLength);

	return 0;
}