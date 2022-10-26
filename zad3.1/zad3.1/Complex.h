#include <iostream>

using namespace std;

class Complex
{
	public: double re, im; // ����� � ������ �����

   Complex() 
   {
	   re = 0;
	   im = 0;
   };
 
   Complex (double r) // ����������� �� ���������
   {
      re = r; 
      im = 0;
   }
 
   Complex (double r, double i) // ����������� �� ���������
   {
      re = r; 
      im = i;
   }

   Complex Conjugate() {
	   return Complex(re, -im);
   }
   double Mod() {
	   return sqrt(re * re + im * im);
   }
   double Arg() {
	   if (Mod() == 0)
		   return 0;
	   else if (re > 0)
		   return atan(im / re);
	   else if (re < 0) {
		   if (im >= 0)
			   return acos(-1) + atan(im / re);
		   else
			   return -acos(-1) - atan(im / re);
	   }
	   else {
		   if (im > 0)
			   return acos(0);
		   if (im < 0)
			   return -acos(0);
	   }
   }



	//friend ostream& operator<<(ostream&, const Complex&); // ���������� ��������� <<
	//friend istream& operator>>(istream&, const Complex&); // ���������� ��������� >>
   Complex& operator = (Complex& c) // ���������� ��������� ������������
   {
       re = c.re;
       im = c.im;

       return (*this);
   }

   Complex operator + (Complex& c) // ���������� ��������� ��������
   {
       Complex temp;

       temp.re = re + c.re;
       temp.im = im + c.re;

       return temp;
   }

   Complex operator - (Complex& c) // ���������� ��������� ���������
   {
       Complex temp;

       temp.re = re - c.re;
       temp.im = im - c.re;

       return temp;
   }

   Complex operator * (Complex& c) // ���������� ��������� ���������
   {
       Complex temp;

       temp.re = re * c.re;
       temp.im = re * c.im;

       return temp;
   }

   Complex operator / (Complex& c) // ���������� ��������� �������
   {
       Complex temp;

       double r = c.re * c.re + c.im * c.im;
       temp.re = (re * c.re + im * c.im) / r;
       temp.re = (im * c.re - re * c.im) / r;

       return temp;
   }


};


inline ostream& operator << (ostream& o, const Complex& c)
{
	return o << '(' << c.re << ", " << c.im << ')';
}

//Complex operator +(const Complex& c)const
//{
//	return Complex(re + c.re, im + c.im);
//}



