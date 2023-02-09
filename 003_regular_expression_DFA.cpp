#include <bits/stdc++.h>
using namespace std;

// For regex: a + (aa)*b
bool acceptOrNot(string input)
{
    int size = input.size();
    if (input[0] == 'a' && size != 1)
    {
        int j = 0;
        while (j < size && input[j] == 'a')
        {
            j++;
        }
        if (j != size - 1 || input[j] != 'b' || j % 2 != 0)
        {
            return 0;
        }
    }
    else if (input[0] == 'b' && size != 1)
    {
        return 0;
    }
    else if (input[0] != 'a' && input[0] != 'b')
        return 0;
    return 1;
}

int main()
{
    string input = "aaaab";
    // string input = "aaab";
    // string input = "aacaab";
    // string input;
    // cin>>input;
    cout << acceptOrNot(input);
    return 0;
}