#include <bits/stdc++.h>
using namespace std;

vector<string> keywords = {"int", "float", "double", "bool"};
vector<char> operators = {'=', '+', '-', '*'};
vector<char> separators = {',', ';', '(', ')', '{', '}', '<', '>'};

vector<string> ansKeywords;
vector<string> ansOperators;
vector<string> ansSeparators;
vector<string> ansIdentifiers;
vector<string> ansConstants;

void checkAndStore(string tempstr)
{
    if (tempstr == " ")
    {
        return;
    }
    // tempstr.pop_back();
    for (auto i : keywords)
    {
        if (i == tempstr)
        {
            cout << i << endl;
        }
    }
}

void identify(string input)
{
    int size = input.size();
    // string tempstr;
    // for (int i = 0; i < size; i++)
    // {
    //     tempstr.push_back(input[i]);
    //     if (input[i] == '_' || input[i] == '$' || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || ((input[i] >= '0' && input[i] <= '9') && input[i - 1] != ' '))
    //         continue;
    //     else
    //     {
    //         cout << tempstr << "|" << endl;
    //         checkAndStore(tempstr);
    //         tempstr = "";
    //     }
    // }
    int i = 0;
    while (i < size)
    {
        if (input[i] == ' ')
        {
            i++;
        }
        else if (i == 0 && input[i] == ' ')
        {
            i++;
        }
        else
        {
            string tempstr;
            while ((i < size))
            {
                if (input[i] == ' ')
                    break;
                tempstr.push_back(input[i]);
                if ((input[i] == '_' || input[i] == '$' || (input[i] >= 'a' && input[i] <= 'z') ||
                     (input[i] >= 'A' && input[i] <= 'Z') ||
                     ((input[i] >= '0' && input[i] <= '9') && !(tempstr.empty()))))
                {
                    i++;
                }
                else if ((input[i] >= '0' && input[i] <= '9'))
                {
                    // tempstr.push_back(input[i]);
                    i++;
                }
                else
                {
                    break;
                }
            }
            cout << tempstr << endl;
            checkAndStore(tempstr);
        }
        i++;
    }
}

int main()
{
    string input = "int x = 5;";
    identify(input);
    return 0;
}