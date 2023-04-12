#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<string> &input, char c)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i][0] == c)
            return i;
    }
    return -1;
}

void findFirst(vector<string> &input, char c, map<char, set<char>> &first)
{
    int i = findIndex(input, c);
    if (input[i][3] >= 'A' && input[i][3] <= 'Z')
    {
        findFirst(input, input[i][3], first);
    }
    else
    {
        first[c].insert(input[i][3]);
    }
}

void findFollow(vector<string> &input, char c, map<char, set<char>> &follow)
{
}

int main()
{
    vector<string> input = {"S->aAS", "A->Ba", "B->cA"};
    map<char, set<char>> first;
    map<char, set<char>> follow;
    for (int i = 0; i < input.size(); i++)
    {
        findFirst(input, input[i][0], first);
    }
    for (auto i : first)
    {
        cout << i.first << " : ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}