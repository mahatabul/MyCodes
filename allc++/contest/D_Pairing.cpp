#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    fastio;

    vector<int> A(4);
    map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> A[i];
        mp[A[i]]++;
        if (mp[A[i]] == 2)
        {
            ans++;
            mp[A[i]] -= 2;
        }
    }
    cout << ans << endl;

    return 0;
}