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

enum EnCharType { SmallLetters = 1, capitalLetters = 2, Charactet = 3, Digit = 4 };

char Type_Of_Charachter(EnCharType CharType)
{
	switch (CharType)
	{
	case EnCharType::SmallLetters:
	{
		return char(guessNumber(97, 122));
		break;
	}
	case EnCharType::capitalLetters:
	{
		return char(guessNumber(65, 90));
		break;
	}
	case EnCharType::Charactet:
	{
		return char(guessNumber(33, 47));
		break;
	}
	case EnCharType::Digit:
	{
		return char(guessNumber(43, 51));
		break;
	}
	default:
	{
		return '\0';
		break;
	}

	}
}

string Generatword(EnCharType CharType, short Length)
{
	string word = "";

	for (int i = 1; i <= Length; i++)
	{
		word += Type_Of_Charachter(CharType);
	}

	return word;
}


string GeneratKey()
{
	string Key = "";

	Key += Generatword(EnCharType::capitalLetters, 4) + "-";
	Key += Generatword(EnCharType::capitalLetters, 4) + "-";
	Key += Generatword(EnCharType::capitalLetters, 4) + "-";
	Key += Generatword(EnCharType::capitalLetters, 4);

	return Key;
}
void Number_Of_Keys(int number)
{
	for (int i = 1; i <= number; i++)
	{
		cout << "Key [" << i << "] : " << GeneratKey() << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));

	Number_Of_Keys(ReadNumber("enter how many keys do you want"));
	return 0;
}