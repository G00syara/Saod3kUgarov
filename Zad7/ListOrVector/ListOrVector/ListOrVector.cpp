#include <iostream>
#include <list>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
	list<int> l;
	int N;
	int M;
	N = 200;                       
	M = 2000;                          
	for (int i = 0; i < N; i++)
	{
		l.push_back(i);
	}
	int k = 0;
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < M; i++)
	{
		l.push_front(20);
		k++;
		l.erase(l.begin());
		k++;
	}
	cout << "List:" << endl;
	auto stop = chrono::steady_clock::now();
	cout << "k = " << k << endl;
	auto dt_l = chrono::duration_cast<chrono::microseconds>(stop - start).count();
	cout << "t = " << dt_l << "ms" << endl << endl;

	vector<int> v;
	N = 200;      
	M = 100;                                 
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}
	k = 0;
	auto startv = chrono::steady_clock::now();
	for (int i = 0; i < M; i++)
	{
		v.insert(v.begin(), 20);
		k++;
		v.erase(v.begin());
		k++;
	}
	cout << "Vector:" << endl;
	auto stopv = chrono::steady_clock::now();
	cout << "k = " << k << endl;
	auto dt_v = chrono::duration_cast<chrono::microseconds>(stopv - startv).count();
	cout << "t = " << dt_v << "ms" << endl;
}