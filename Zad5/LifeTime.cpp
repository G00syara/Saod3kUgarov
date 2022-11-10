#include "Child.h"
#include "Aggregate.h"
#include "Test.h"
#include "AggregateT.h"

using namespace std;

Test glob("global");

void foo(Test t) {
	cout << "foonction" << endl;
}

int main() {
	Test t("nGlobal");
	Test *p = new Test("dynamic");
	delete p;
	p = new Test[4];
	delete[] p; 
	foo(t);
	Child ch;
	Aggregate aggr = Aggregate();
	AggregateT<Test> templateTest = AggregateT<Test>();
	AggregateT<Child> templateChild = AggregateT<Child>();

	return 0;
}
