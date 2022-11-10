#include "Str.h"
#include <iostream>

using namespace std;

void Test(Str s) {}

int main() {
	Str s = "123";
	cout << s << " Length: " << strlen(s) << endl;
	Test(s);
	cout << s << " Length: " << strlen(s) << endl;
	Str t;
	t = s;
	cout << "s: " << s << " Length: " << strlen(s) << endl;
	cout << "t: " << t << " Length: " << strlen(t) << endl;
	t = s = t;
	Str a = "abc";
	Str b = "123";
	cout << a + b << endl;
	a += b;
	cout << a << endl;
}
