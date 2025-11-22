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
    map<string, ll> mp;

    for (ll i = 0; i < n; i++)
    {
        ll price;
        string s;
        cin >> price >> s;
        sort(s.begin(), s.end());
        if (mp.count(s))
        {
            mp[s] = min(mp[s], price);
        }
        else
        {
            mp[s] = price;
        }
    }

    ll ans = INT_MAX;
    if (mp.count("A") && mp.count("B") && mp.count("C"))
    {
        ans = min(ans, mp["A"] + mp["B"] + mp["C"]);
    }
    if (mp.count("A") && mp.count("BC"))
    {
        ans = min(ans, mp["A"] + mp["BC"]);
    }
    if (mp.count("B") && mp.count("AC"))
    {
        ans = min(ans, mp["B"] + mp["AC"]);
    }
    if (mp.count("C") && mp.count("AB"))
    {
        ans = min(ans, mp["C"] + mp["AB"]);
    }
    if (mp.count("AB") && mp.count("BC"))
    {
        ans = min(ans, mp["AB"] + mp["BC"]);
    }
    if (mp.count("AB") && mp.count("AC"))
    {
        ans = min(ans, mp["AB"] + mp["AC"]);
    }
    if (mp.count("AC") && mp.count("BC"))
    {
        ans = min(ans, mp["AC"] + mp["BC"]);
    }
    if (mp.count("ABC"))
    {
        ans = min(ans, mp["ABC"]);
    }

    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}