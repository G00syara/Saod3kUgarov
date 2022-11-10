#pragma once
#include <iostream>

using namespace std;

template <class T>
class AggregateT {
	public:
		T m_obj = T();

		AggregateT() {
			cout << "Template constructor" << endl;
		}

		~AggregateT() {
			cout << "Template destructor" << endl;
		}
};
