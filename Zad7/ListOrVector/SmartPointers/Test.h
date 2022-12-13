#pragma once
#include <iostream>
using namespace std;


class Test
{
public:
	int Val;
	Test()
	{
		Val = 0;
		cout << "Test has been created!" << endl;
	}
	~Test()
	{
		cout << "Test has been deleted!" << endl;
	}
};