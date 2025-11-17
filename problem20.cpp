#include<iostream>
#include<string> 
//#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
//#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.

using namespace std;

int guessNumber(int From, int To)
{

	// Function to generete a random number

	int number = rand() % (To - From + 1) + From;


	return number;
}

enum Enrandom { SmallLetters = 1, CapitalLetters = 2, SpecialCharacter = 3, DigitInOrder = 4 };

char GetRandomCharacter(Enrandom random)
{
	switch (random)
	{
	case Enrandom::SmallLetters:
	{
		return char(guessNumber(97, 122));
		break;
	}
	case Enrandom::CapitalLetters:
	{
		return char(guessNumber(65, 90));
		break;
	}
	case Enrandom::SpecialCharacter:
	{
		return char(guessNumber(33, 47));
		break;
	}
	case Enrandom::DigitInOrder:
	{
		return char(guessNumber(48, 57));
		break;
	}
	}

	return '\0';

}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(Enrandom::SmallLetters) << endl;
	cout << GetRandomCharacter(Enrandom::CapitalLetters) << endl;
	cout << GetRandomCharacter(Enrandom::SpecialCharacter) << endl;
	cout << GetRandomCharacter(Enrandom::DigitInOrder) << endl;
	return 0;
}