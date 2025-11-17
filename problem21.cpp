#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

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
int guessNumber(int From, int To)
{

	// Function to generete a random number

	int number = rand() % (To - From + 1) + From;


	return number;
}

string charGenerate()
{
	string word = "";

	for (int i = 1; i <= 4; i++)
	{
		word += char(guessNumber(65, 90));
	}
	return word;
}
string keyGenerate()
{
	string fullkey = "";

	for (int i = 1; i <= 4; i++)
	{
		if (i < 4)
		{
			fullkey += (charGenerate() + char(45));
		}
		else
		{
			fullkey += (charGenerate());
		}

	}
	return fullkey;
}
void keys(int number)
{
	for (int i = 1; i <= number; i++)
	{
		system("color 6f");
		cout << "Key [ " << i << " ] : " << keyGenerate() << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));

	keys(ReadNumber("enter  how many keys do you want"));

	return 0;
}