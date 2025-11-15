#include<iostream>

#include<string> 

using namespace std;

//                                   print Invered number pattern program
int readnumbers(string Message)
{
	int number = 0;

	do
	{
		cout << Message << endl;
		cin >> number;
	} while (number <= 0);

	return number;

}
void InvertedNumberPattern(int number)
{

	for (int i = number; i >= 1; i--)
	{
	
		for (int j = 1; j <= i; j++)
		{
			cout << i;
			
		}
		cout << endl;
	
	}
}
int main()
{
	
	 InvertedNumberPattern(readnumbers("enter a positive number"));
	
		
	return 0;
}
