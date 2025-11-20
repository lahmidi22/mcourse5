#include<iostream>
#include<string> 

using namespace std;

int ReadNumber(string Message)
{
	int number = 0;
	do
	{
		cout << Message << endl;
		cin >> number;

	} while (number < 0);

	return number;
}
void  ReadArray(int arr[100], int& arrlength)
{

	cout << "enter array element :" << endl;
	cin >> arrlength;

	int i = 0;

	while (i < arrlength)
	{

		cout << "Element [" << i + 1 << "] : ";

		cin >> arr[i];
		i++;

	}
	cout << endl;

}
void PrintArray(int arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int TimesRepeated(int number, int arr[100], int arrlength)
{
	int Elementtotal = 0;


	for (int i = 0; i < arrlength; i++)
	{
		if (number == arr[i])
		{
			Elementtotal++;
		}
	}


	return Elementtotal;
}

int main()
{

	int arr[100], arrlength = 0;

	ReadArray(arr, arrlength);


	int NumberToCheck = ReadNumber("enter the number want to check?");

	cout << "\nOriginal array: :";
	PrintArray(arr, arrlength);

	cout << NumberToCheck;

	cout << " is repeated ";
	cout << TimesRepeated(NumberToCheck, arr, arrlength) << " time(s)";

	return 0;
}