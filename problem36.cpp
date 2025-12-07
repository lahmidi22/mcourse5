#include<iostream>
#include<string> 

using namespace std;

int ReadNumber()
{
	int Number = 0;

	cout << "please enter a number? ";
	cin >> Number;

	return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;

}
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
	bool AdMore = true;
	do
	{
		AddArrayElement(ReadNumber(), arr, arrLength);
		cout << "\nDo you want to add more numbers? [0]No, [1]Yes ? : ";
		cin >> AdMore;
	} while (AdMore);
}
void PrintArray(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int main()
{
	int arr[100], arrLength = 0;
	InputUserNumbersInArray(arr, arrLength);

	cout << "\nArray Length: " << arrLength << endl;
	cout << "Array elements: ";
	PrintArray(arr, arrLength);


	return 0;
}