#include <iostream>
#include <memory>
#include "Test.h"

int main()
{
	unique_ptr<Test[]> p(new Test[3]);
	cout << p[1].Val << endl;
	p[0].Val = 0;
	p[1].Val = 1;
	p[2].Val = 2;
	for (int i = 0; i < 3; i++)
	{
		cout << p[i].Val << endl;
	}
	cout << "---------" << endl;
	p.reset(new Test[2]);
	cout << "---------" << endl;
}