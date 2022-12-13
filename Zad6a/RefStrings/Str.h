#pragma once
#include "_str.h"

class Str
{
	_str* m_pStr;
public:

	int rfind(const char* t, int off) const
	{
		int lenThisStr = len();
		int lenT = strlen(t);
		if (lenThisStr < lenT || lenT == 0 || off > lenThisStr)
		{
			return -1;
		}

		for (char* i = m_pStr->m_pszData + off - 1; i - m_pStr->m_pszData >= 0; i--)
		{
			char* iPer = i;
			for (const char* j = t; j - t < lenT; j++)
			{
				if (*iPer != *j)
					break;
				iPer++;
				if (j - t == lenT - 1) return i - m_pStr->m_pszData;
			}
		}
		return -1;
	}
	Str()
	{
		m_pStr = new _str;
	}

	Str(const char* p)
	{
		m_pStr = new _str(p);
	}

	Str(const Str &s)
	{
		m_pStr = s.m_pStr;
		m_pStr -> AddRef();
	}

	operator const char* ()const 
	{
		return m_pStr -> m_pszData;
	}

	Str& operator = (const Str& s)
	{
		if (this != &s)
		{
			s.m_pStr -> AddRef();
			m_pStr -> Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	Str& operator += (const Str& s)
	{
		int length = len() + s.len();
		if (s.len() != 0)
		{			
			_str* pstrTmp = new _str; 	
			delete[] pstrTmp -> m_pszData;
			pstrTmp -> m_pszData = new char[length + 1];
			strcpy_s(pstrTmp -> m_pszData, length + 1, m_pStr -> m_pszData);
			strcat_s(pstrTmp -> m_pszData, length + 1, s.m_pStr -> m_pszData);
			m_pStr -> Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	~Str()
	{
		m_pStr -> Release(); 
	}				

	int len() const
	{
		return strlen(m_pStr -> m_pszData);
	}
};