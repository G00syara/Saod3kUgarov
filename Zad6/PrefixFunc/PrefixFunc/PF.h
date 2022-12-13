#pragma once
#include <stdexcept>

class PF
{
	int* pv;
	int n;
	int cmp; //кол-во сравнений, дл€ вычислени€ логической сложности алогоритма
public:
	PF()
	{
		//–ешаем проблему с двойно инициализацией
		pv = new int[1] {0};
		n = 0;
		cmp = 0;
	}


	void Init(const char* s)
	{
		//–ешаем проблему с двойно инициализацией
		delete[] pv;
		n = strlen(s);
		pv = new int[n];
		for (int i = 0; i < n; i++)
			pv[i] = 0;
		int k = 0;
		cmp = 0;
		for (int i = 1; i < n; i++)
		{
			cmp++;
			if (s[i] == s[k])
				pv[i] = ++k; //ѕрактически первый раз в жизни используем префикс
			else
				if (!k) //k==0
					pv[i] = k = 0;
				else
				{
					k = pv[k - 1];
					i--;
				}
		}
	}

	operator int() const 
	{
		return n;
	}

	int CmpCount() const
	{
		return cmp;
	}

	int operator [](int i)const
	{
		if (i < 0 || i >= n)
			throw std::out_of_range("Index out of range");
		return pv[i];
	}

	~PF()
	{
		delete[] pv;
	}
};

