#include <iostream>
using namespace std;
#include "Str.h"


int main()
{
    Str obj1("An honest man is the noblest work of God.");
    cout << obj1 << endl << endl;
    
    cout << "What does the method return if it searches for an ''?" << endl;
    cout << "Search '' with 10 offset parameter:  " << obj1.rfind("", 10) << endl << endl;

    cout << "b) What does the method return if there are two occurrences of the pattern before the off position?" << endl;
    cout << "Search 'honest' in string:  " << obj1.rfind("honest", 5) << endl << endl;

}



