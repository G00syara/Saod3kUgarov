#pragma once
#include "Test.h"

class Aggregate {
	public:
		Test m_objTest = Test("aggregate test");

		Aggregate();
		~Aggregate();
};
