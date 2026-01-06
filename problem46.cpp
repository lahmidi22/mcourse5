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
float MyABS(float number)
{
	if (number > 0)
	{
		return number;
	}
	else
	{
		return number * (-1);
	}

}

int main()
{
	float number = readnumber();

	cout << "My abs result : " << MyABS(number) << endl;


	cout << "c++ abs result: " << abs(number) << endl;



	return 0;
}