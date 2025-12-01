#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int randnumber = rand() % (To - From + 1) + From;
	return randnumber;
}

char RandomCharType(enCharType charType)
{
	switch (charType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 120));
		break;
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
		break;
	case enCharType::SpecialCharacter:
		return char(RandomNumber(33, 47));
		break;
	case enCharType::Digit:
		return RandomNumber(1, 100);
		break;
	default:
		return '\0';
		break;
	}
}
string  GeneratWord(int Length)
{
	string word = "";

	for (int i = 1; i <= Length; i++)
	{
		word += RandomCharType(enCharType::CapitalLetter);

	}
	return word;
}



string  GeneratKey(int Number)
{
	string Key = "";

	Key += GeneratWord(4) + "-";
	Key += GeneratWord(4) + "-";
	Key += GeneratWord(4) + "-";
	Key += GeneratWord(4);

	return Key;
}

void FillArrayWithKeys(string arr[100], int Number)
{
	for (int i = 0; i < Number; i++)
	{
		arr[i] = GeneratKey(Number);
	}

}

void GeneratKeys(string arr[100], int Number)
{

	for (int i = 0; i < Number; i++)
	{
		cout << "array [ " << i << " ] : ";
		cout << arr[i] << endl;

	}
}


int main()
{
	srand((unsigned)time(NULL));

	string arr[100];

	int Number = ReadPositiveNumber("entr how many Keys do you want");
	FillArrayWithKeys(arr, Number);
	GeneratKeys(arr, Number);




	return 0;
}