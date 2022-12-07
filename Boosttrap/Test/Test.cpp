#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

double mean(vector<double> samples)
{
	double sum = accumulate(samples.begin(), samples.end(), 0.0);
	return sum / samples.size();
}

int main()
{

	cout << scientific;
	cout.precision(2);


	vector<double> m = { 0.0855298042e+00, 1.4513241053e+00, 1.3237277269e+00, 1.0128350258e+00, 1.4122089148e+00, 6.5826654434e-01, 2.0795986652e+00, 1.0230206251e+00, 1.4231411219e+00, 1.1091691256e+00, 1.7714337111e+00, 1.3986129761e+00, 1.0640757084e+00, 1.4216910601e+00, 1.2402026653e+00 };
	float median;
	int medindex;
	double iqr;
	double q1;
	double q3;
	double Min;
	double Max;
	int outliers[100];
	int x;
	int z;
	int n = 14;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (m[i] < m[j])
				swap(m[i], m[j]);
		}
	}

	cout << "sorted numbers are : " << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << m[i] << " ";
	}

	cout << " " << endl;


	if (n == 2) // exeption if we had 2 numbers we wont have q1 and q2 
	{
		median = (m[1] + m[2]) / 2;
		cout << endl << "median is :" << " " << median << endl;
		cout << " there is no q1 and q3";
	}

	else if (n % 2 == 1) // if n is odd
	{
		median = m[(1 + n) / 2];
		medindex = (1 + n) / 2;
		if ((medindex - 1) % 2 == 1)
		{
			q1 = m[((medindex - 1) + 1) / 2];
			q3 = m[(n + (medindex + 1)) / 2];

		}
		else
		{
			x = (((medindex - 1) + 1) / 2);
			z = x + 1;
			q1 = ((double)m[x] + m[z]) / 2;
			int b = (n + (medindex + 1)) / 2;
			int c = b + 1;
			q3 = ((double)m[b] + m[c]) / 2;
		}
		cout << " median is :" << " " << median << endl;
		cout << "q1 is : " << " " << q1 << endl;
		cout << "q3 is : " << " " << q3 << endl;

	}
	else // if n is even
	{

		int s1 = (n + 1) / 2;
		int s2 = s1 + 1;
		median = ((double)m[s1] + m[s2]) / 2;



		if ((n / 2) % 2 == 1)
		{
			q1 = m[(s1 + 1) / 2];
			q3 = m[(n + s2) / 2];
		}
		else
		{
			int l = (s1 + 1) / 2;
			int l1 = l + 1;
			int h = (s2 + n) / 2;
			int h1 = h + 1;
			q1 = ((double)m[l] + m[l1]) / 2;
			q3 = ((double)m[h] + m[h1]) / 2;
		}
		cout << " median is :" << " " << median << endl;
		cout << "q1 is : " << " " << q1 << endl;
		cout << "q3 is : " << " " << q3 << endl;
	}

	Min = q1 - 1.5*(q3-q1);
	Max =  q3 + 1.5*(q3-q1);

	cout << "Max is : " << " " << Max << endl;
	cout << "Min is : " << " " << Min << endl;

	cout << "Mean is :  " << mean(m) << endl;

	// finding outliers 
	iqr = q3 - q1;
	int p = 0;
	double k1 = (q1 - 1.5 * iqr);
	double k2 = q3 + 1.5 * iqr;
	for (int i = 1; i <= n; i++)
	{
		if (m[i]<k1 || m[i]>k2)
		{
			outliers[p] = m[i];
			p++;
		}

	}

	double stddev = 0.;
	for (int i = 0; i < n; i++)
	{
		stddev += pow(m[i] - mean(m), 2);
	}
	stddev /= n - 1;
	stddev = sqrt(stddev);

	cout << "Stddev: " << stddev << endl;

	if (p == 0)
	{
		cout << " there are no outliers " << endl;
	}

	else
	{
		cout << "outliers are: " << endl;
		for (int i = 0; i < p; i++)
		{
			cout << outliers[i] << " ";
		}
	}

	cout << mean(m) << endl;

	return 0;
}