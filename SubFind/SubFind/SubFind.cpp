#include <iostream>
#include<chrono>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

size_t naive(const string& str, const string& sub) {
    size_t n = str.size(), m = sub.size(), j = 0;
    for (size_t i = 0; i < n - m + 1; i++) {
        for (j = 0; j < m; j++) {
            if (str[i + j] != sub[j])
                break;
        }
        if (j == m)
            return i;
    }
    return string::npos;
}
//


size_t kmp(const string& str,const  string& sub)
{
    size_t l = sub.size();
    size_t* pi = new size_t[l];
    pi[0] = 0;
    for (int i  = 1;i< l ; ++i)
    {
        size_t j = pi[i - 1];
        while ((j > 0) && (sub[i] != sub[j]))
            j = pi[j - 1];	     
        if (sub[i] == sub[j])      
            ++j;
        pi[i] = j;
    }
    size_t j = 0;
    for (size_t i = 0; i < str.size() - sub.size() + 1; ++i)
    {
        while ((j > 0) && (str[i] != sub[j]))
            j = pi[j - 1];

        if (str[i] == sub[j])
            ++j;
        if (j == l)
        {
            delete[] pi;
            return i - l + 1;
        }
    }
    return string::npos;
}

static int Max(int a, int b) {
    return a >= b ? a : b;
}

static void BadCharHeuristic(string str, int size, int* badChar) {
    int i;

    for (i = 0; i < 256; i++)
        badChar[i] = -1;

    for (i = 0; i < size; i++)
        badChar[(int)str[i]] = i;
}

size_t bm(const string& str, const string& sub) {
    int m = sub.length();
    int n = str.length();

    int* badChar = new int[256];

    BadCharHeuristic(sub, m, badChar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && sub[j] == str[s + j])
            --j;

        if (j < 0)
        {
            return s;
        }
        else
        {
            s += Max(1, j - badChar[str[s + j]]);
        }
    }
    delete[] badChar;
    return string::npos;
}


int main()
{
    string str, sub = "was born in a small town called Sceptre";
    ifstream fin("engwiki_ascii.txt", ios::binary);
    if (!fin.is_open())
    {
        cout << "not open!" << endl;
        return 0;
    }
    str.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    size_t n = 10;
    std::vector<size_t> times(n), indx(n);

    cout << "\nstd::find\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = str.find(sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::nanoseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }

    cout << "\nnaive\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = naive(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::nanoseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }

    cout << "\nKMP\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = kmp(str,sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::nanoseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }

    cout << "\nBM\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = bm(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::nanoseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
}
