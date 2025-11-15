#include<iostream>
#include<string> 

using namespace std;

string ReadPassword(string Message)
{
	string Password = "";

	cout << Message << endl;
	cin >> Password;

	return Password;

}

bool GuessPassword(string OriginalPassword)
{
	int counter = 0;
	cout << "\n";
	string word = "";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word += char(i);
				word += char(j);
				word += char(k);

				counter += 1;

				cout << "Trial[" << counter << "] : " << word << endl;

				if (word == OriginalPassword)
				{
					cout << "password is " << word << endl;
					cout << "Found after " << counter << " Trial(s)";
					return true;
				}


				word = "";


			}
		}
	}
	return false;
}

int main()
{

	GuessPassword(ReadPassword("Please enter a 3-Letter Password (all capital"));

	return 0;
}

