#include <bits/stdc++.h>
#include <string>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long

bool wordBreak(string s, vector<string> &wordDict)
{
    for (auto it : wordDict)
    {
        if (s.find(it) != string::npos)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    fast_io;

    return 0;
}