#include<iostream>
#include<string> 

using namespace std;

int RandomNumber(int From, int To)
{
	int number = rand() % (To - From + 1) + From;

	return number;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "enter numbr of element" << endl;
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{

		arr[i] = RandomNumber(1, 100);

	}

}

void AddAraayElement(int number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = number;

}

void CopyOddNumbers(int arr[100], int arr2[100], int arrLength, int& arr2Length)
{

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 != 0)
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
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	int arr2[100], arr2Length = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	CopyOddNumbers(arr, arr2, arrLength, arr2Length);

	cout << "array 1 elements : " << endl;
	PrintArrayElement(arr, arrLength);

	cout << endl;

	cout << "array 2  after copy odd elements  : " << endl;
	PrintArrayElement(arr2, arrLength);

	return 0;
}