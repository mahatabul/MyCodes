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

    ll n;
    cin >> n;
    string ans;
    ll maxvotes = 0;
    map<string, ll> king;

    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        king[s]++;
        if (king[s] > maxvotes)
        {
            maxvotes = king[s];
            ans = s;
        }
    }

    cout << ans << endl;

    return 0;
}