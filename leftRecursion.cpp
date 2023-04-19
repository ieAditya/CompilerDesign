#include <bits/stdc++.h>
using namespace std;

vector<string> removeLR(string input)
{
    vector<string> recProds;
    vector<string> nonRecProds;

    int i = 3;
    while (i < input.length())
    {
        if (input[i] == input[0])
        {
            string temp = "";
            int j = i + 1;
            while (j < input.length())
            {
                if (input[j] == '|')
                {
                    break;
                }
                temp.push_back(input[j]);
                j++;
            }
            recProds.push_back(temp);
            i = j + 1;
        }
        else
        {
            string temp = "";
            int j = i;
            while (j < input.length())
            {
                if (input[j] == '|')
                {
                    break;
                }
                temp.push_back(input[j]);
                j++;
            }
            nonRecProds.push_back(temp);
            i = j + 1;
        }
    }

    vector<string> ans;
    ans.push_back("S->");
    for (auto i : recProds)
    {
        ans[0] = ans[0] + i + 'Z' + '|';
    }
    ans.push_back("Z->");
    for (auto i : nonRecProds)
    {
        ans[1] = ans[1] + i + 'Z' + "|";
    }
    ans[1] += "|epsilon";
    return ans;
}

int main()
{
    string input = "S->a|zc|Sbd";
    vector<string> ans = removeLR(input);

    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}