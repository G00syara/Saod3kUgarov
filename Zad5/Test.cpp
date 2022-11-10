#include "Test.h"

int Test::nCount = 0;

Test::Test() {
	nCount++;
	Test::name = to_string(nCount);
	cout << Test::name << " c..." << "Total obj count: " << nCount << endl;
}

Test::Test( const Test &t ) {
	nCount++;
	Test::name = t.name + " copy";
	cout << Test::name << " c..." << "Total obj count: " << nCount << endl;
}

Test::Test( string n ) {
	nCount++;
	Test::name = n;
	cout << n << " c..." << "Total obj count: " << nCount << endl;
}

Test::~Test() {
	nCount--;
	cout << Test::name << " d..." << "Total obj count: " << nCount << endl;
}
