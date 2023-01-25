#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}

string pigLatin(string word)
{
    string ans;
    int i = 0;
    if (word.size() == 1)
    {
        return word;
    }
    else
    {
        while (i < word.size() && !isVowel(word[i]) && !(i > 0 && word[i] == 'y' && !isVowel(word[i - 1])))
        {
            if (i + 1 < word.size() && word[i] == 'q' && word[i + 1] == 'u')
            {
                i++;
            }
            i++;
        }
    }

    if (i > 0)
    {
        string temp = "";
        for (int j = 0; j < i; j++)
        {
            temp.push_back(word[j]);
        }
        for (int j = i; j < word.size(); j++)
        {
            ans.push_back(word[j]);
        }
        ans = ans + temp + "ay";
    }
    else
        ans = word + "yay";
    return ans;
}

int main()
{
    string word = "queue";
    string word2 = "paris";
    string word3 = "amazon";
    string word4 = "graphic";
    string ans = pigLatin(word);
    cout << ans << endl;
    ans = pigLatin(word2);
    cout << ans << endl;
    ans = pigLatin(word3);
    cout << ans << endl;
    ans = pigLatin(word4);
    cout << ans << endl;
    return 0;
}