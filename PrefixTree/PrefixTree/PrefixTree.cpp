#include "PrefixTree.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void triedict(const string& text, string word) {
    PrefixTree dict;
    string str = "";
    for (const auto& ch : text) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '\'')
            str += ch;
        else if (str.size() > 0) {
            dict.insert(str);
            str = "";
        }
    }
    cout << "\ndict size: " << dict.size() << endl;
    cout << word << ": " << dict.find(word) << endl;
}

void umap(const string& text, string word) {
    unordered_map<string, size_t> dict;
    string str = "";
    for (const auto& ch : text) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '\'')
            str += ch;
        else if (str.size() > 0) {
            ++dict[str];
            str = "";
        }
    }
    cout << "\ndict size: " << dict.size() << endl;
    cout << word << ": " << dict[word] << endl;
}

int main() {
    string text;
    ifstream fin("engwiki_ascii.txt", ios::binary);
    if (!fin.is_open()) {
        cout << "not open!" << endl;
        return 0;
    }
    text.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    string word = "a"; // слово которое ищем
#define test_func(func_name) \
    { \
        auto time_one = chrono::steady_clock::now(); \
        func_name(text, word); \
        auto time_two = chrono::steady_clock::now(); \
        cout << #func_name << "\t" \
             << chrono::duration_cast<chrono::microseconds>(time_two - \
                                                            time_one) \
                        .count() / \
                    1e6 \
             << " sec\n"; \
    }

    test_func(umap);
    test_func(triedict);
#undef test_func
}