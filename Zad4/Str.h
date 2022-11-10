#include <string.h>

using namespace std;

class Str {
	char* m_pszText;
	public:
	Str () {
		m_pszText = new char[1]{0};
	}

	Str (const char * p) {
		if(p) {
			m_pszText = new char [strlen(p) + 1];
			strncpy(m_pszText, p,strlen(p) + 1);
		}
		else
			m_pszText = new char[1]{0};
	}

	Str (const Str &s)
	{
		m_pszText = new char [strlen(s.m_pszText) + 1];
		strncpy(m_pszText, s.m_pszText, strlen(s.m_pszText) + 1);
	}

	~Str () { 
		delete []m_pszText;
	}

	operator const char *()const { return m_pszText; }
	Str & operator +=(const char *sz) {
		char *a = new char[strlen(m_pszText) + strlen(sz)];
		strncpy(a, m_pszText, strlen(m_pszText) + 1);
		strncat(a, sz, strlen(sz) + 1);
		this->m_pszText = a;
		return *this;
	}

	Str operator +(const char *sz) const {
		char *a = new char[strlen(m_pszText) + strlen(sz)];
		strncpy(a, m_pszText, strlen(m_pszText));
		strncat(a, sz, strlen(sz) + 1);
		return Str(a);
	}

	const Str& operator = (const Str &s) {
		if(&s == this) return *this;
		delete [] m_pszText;
		m_pszText = new char [strlen(s.m_pszText) + 1];
		strncpy(m_pszText, s.m_pszText, strlen(s.m_pszText) + 1);
		return *this;
	}
};
