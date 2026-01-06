#include<iostream>
#include<string> 
#include<cmath>
using namespace std;

float readnumber()
{
	float number = 0;

	cout << "enter number" << endl;
	cin >> number;
	return number;
}
float GetFractionPart(float number)
{
	return number - int(number);
}
int MyRound(float number)
{
	int Intpart;
	Intpart = int(number);

	float FractionPart = GetFractionPart(number);

	if (abs(FractionPart) >= .5)
	{
		if (number > 0)
		{
			return ++Intpart;
		}
		else
		{
			return --Intpart;
		}
	}
	else
	{
		return Intpart;
	}

}

int main()
{
	float number = readnumber();

	cout << "My round result : " << MyRound(number) << endl;

	cout << "c++ round result: " << round(number) << endl;



	return 0;
}