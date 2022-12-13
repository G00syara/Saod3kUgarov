#include <iostream>
#include "PF.h"
 

int main()
{
	using namespace std;
	PF pf;
	pf.Init("rakaratrakarakarakatakarakara");
	for (size_t i = 0; i < 29; i++)
		cout << pf[i];
	cout << endl;

	int N;
	char* s;
	for (int i = 1; i < 4; i++)
	{
		N = 100 * i;
		s = new char[N] {0};
		for (int i = 0; i < N - 1; i++)
			s[i] = rand() % ('c' - 'a') + 'a';
		pf.Init(s);
		cout << pf.CmpCount() << endl;
		delete[] s;
	}
}


