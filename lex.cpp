#include <bits/stdc++.h>
using namespace std;
vector<string> resKey;
vector<string> resOp;
vector<string> resDel;
vector<string> resInt;
vector<string> resId;

void print()
{
    cout << "Keywords: ";
    for (auto i : resKey)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Operators: ";
    for (auto i : resOp)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Delimiters: ";
    for (auto i : resDel)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Identifiers: ";
    for (auto i : resId)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Constants: ";
    for (auto i : resInt)
    {
        cout << i << " ";
    }
}

int chkInt(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int chkAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int chkOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '!' || c == '>' || c == '<' || c == '&' || c == '|' || c == '^' || c == '~' || c == '?' || c == ':')
    {
        return 1;
    }
    return 0;
}

int chkDelimiter(char c)
{
    if (c == ' ' || c == ',' || c == ';')
    {
        return 1;
    }
    return 0;
}

void resKeyword(string s)
{
    vector<string> keyword = {"alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit",
                              "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case",
                              "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const",
                              "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await", "co_return",
                              "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum",
                              "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int",
                              "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or",
                              "or_eq", "private", "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires",
                              "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch",
                              "synchronized", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
                              "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};
    for (int i = 0; i < keyword.size(); i++)
    {
        if (s == keyword[i])
        {
            resKey.push_back(s);
            return;
        }
    }
    if (s != "")
    {
        resId.push_back(s);
    }
}

void operators(string s)
{
    vector<string> operators = {"+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", ">>=", "<<=", "&=", "|=", "^=", "?:", ",", ".", "->", ".*", "->*", "()", "[]", "new", "delete", "new[]", "delete[]"};
    for (auto it = operators.begin(); it != operators.end(); it++)
    {
        if (s == *it)
        {
            resOp.push_back(s);
        }
    }
}

void delimiters(string s)
{
    vector<string> delimtr = {",", ";", "(", ")", "{", "}", "[", "]", "#", "\\", "<", ">", "~", "`", "'", "\""};
    for (int i = 0; i < delimtr.size(); i++)
    {
        if (s == delimtr[i])
        {
            resDel.push_back(s);
        }
    }
}

int main()
{
    string s = "int a+= 10; x+++y hghh hh989h ,h intn;";

    string tempstr = "", tempint, tempop, tempdel;
    for (int i = 0; i < s.length(); i++)
    {
        if (!chkDelimiter(s[i]))
        {
            if (chkAlphabet(s[i]) || ((chkInt(s[i])) && (chkAlphabet(s[i - 1]))))
            {
                // if integer is after alphabet
                if (chkInt(s[i]) && chkAlphabet(s[i - 1]))
                {
                    int j = i;
                    // put all interger in tempstr until delimiter
                    while (!chkDelimiter(s[j]))
                    {
                        tempstr += s[j];
                        j++;
                    }
                    i = j;
                    continue;
                }

                tempstr += s[i];
            }
            else if (chkInt(s[i]) || (s[i] == '.' && (chkInt(s[i - 1]) || chkInt(s[i + 1]))))
            {
                tempint += s[i];
            }
            else if (chkOperator(s[i]))
            {
                tempop += s[i];
            }
        }
        else
        {
            if (chkDelimiter(s[i]))
            {
                tempdel += s[i];
            }
            if (tempint != "")
            {
                resInt.push_back(tempint);
            }

            delimiters(tempdel);
            operators(tempop);
            resKeyword(tempstr);

            tempstr = "";
            tempop = "";
            tempdel = "";
            tempint = "";
        }
    }

    print();
    return 0;
}