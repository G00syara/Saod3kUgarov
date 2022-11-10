#include "Child.h"
#include <iostream>

Child::Child() {
	cout << "child c " << "name " << Child::name << " Total obj count: " << Child::nCount << endl; 
}

Child::~Child() {
	cout << "child d " << "name " << Child::name << " Total obj count: " << Child::nCount << endl; 
}
