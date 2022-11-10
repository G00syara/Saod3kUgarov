#pragma once
#include <iostream>

using namespace std;

class Test {
	public:
		static int nCount;
		string name;

		Test( string n ); 
		Test( const Test &t );
		Test(); 
		~Test();
};
