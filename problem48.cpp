#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify usage of standard functions.

/
int MyFloor(float Number)
{
    
    if (Number > 0)
        return int(Number);
    else
      
        return int(Number) - 1;
}


float ReadNumber()
{
    float Number;  

   
    cout << "Please enter a number? ";
    cin >> Number;  

    return Number;  
}

int main()
{
    float Number = ReadNumber(); 

  
    cout << "My MyFloor Result : " << MyFloor(Number) << endl;

   
    cout << "C++ floor Result  : " << floor(Number) << endl;

    return 0; 
}