#include<iostream>
#include<string> 
// #include <cstdlib>    // Include cstdlib for rand() and srand() functions.
// #include <ctime>      // Include ctime for the time() function.

using namespace std;

int Randomnumber(int From, int To)
{
	int rand_Num = rand() % (To - From + 1) + From;
	return rand_Num;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << Randomnumber(1, 10) << endl;
	cout << Randomnumber(1, 10) << endl;
	cout << Randomnumber(1, 10) << endl;

	return 0;
}