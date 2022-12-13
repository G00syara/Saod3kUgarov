#include "WF.h"
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <fstream>

int main()
{

	WF test = WF();
	std::ifstream prev("prev.txt");
	std::ifstream curr("curr.txt");
	test.Compare(prev,curr);
	std::cout << "Ditance " << test.Distance() << std::endl;
	std::cout << "Rows " << test.Rows() << std::endl;
	std::cout << "Columns " << test.Columns() << std::endl;
	std::cout << test.Prescription() << std::endl;
	//std::cout << test.CurLine(1) << std::endl;
	//std::cout << test.PrevLine(7) << std::endl;
	//for (int i = 0; i <= 114; i++)
	//{
	//	for (int j = 0; j <= 115; j++)
	//		std::cout << test.pm[i + j * 115] << "  ";
	//	std::cout << '\n';
	//}
	//for (int i = 0; i < 2859; i++)
	//	if (test.pm[i] == 0)
	//		std::cout << i << std::endl;;
//	std::cout << test.Get(50, 50) << std::endl;
	//test.Set(1, 1, 5);
	//std::cout << test.Get(1, 1) << std::endl;
}