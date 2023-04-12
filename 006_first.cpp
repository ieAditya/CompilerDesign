#include <bits/stdc++.h>
using namespace std;

char findFirst(vector<string> input, int i)
{
    char tobesearch;
    if (input[i][3] >= 'A' && input[i][3] <= 'Z')
    {
        tobesearch = input[i][3];

        for (int k = 0; k < input.size(); k++)
        {
            if (input[k][0] == tobesearch)
                return findFirst(input, k);
        }
    }
    else
        return input[i][3];
}

int main()
{
    vector<string> input = {"S->aAS", "S->bAs", "A->Ba", "B->cA"};
    map<char, set<char>> first;
    for (int i = 0; i < input.size(); i++)
    {
        first[input[i][0]].insert(findFirst(input, i));
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