#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (mpp.count(x - a))
        {
            cout << i + 1 << " " << mpp[x - a];
            return 0;
        }
        mpp[a] = i + 1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}