#include <bits/stdc++.h>
using namespace std;

bool isCKeyword(string input)
{
    vector<string> cKeywords = {"auto", "double", "int", "struct",
                                "break", "else", "long", "switch",
                                "case", "enum", "register", "typedef",
                                "char", "extern", "return", "union",
                                "continue", "for", "signed", "void",
                                "do", "if", "static", "while",
                                "default", "goto", "sizeof", "volatile",
                                "const", "float", "short", "unsigned"};

    for (auto i : cKeywords)
    {
        if (i == input)
            return 1;
    }
    return 0;
}

int main()
{
    string input;
    cin >> input;
    if (isCKeyword(input))
        cout << input << " is a c keyword";
    else
        cout << input << " is not a c keyword";
    return 0;
}