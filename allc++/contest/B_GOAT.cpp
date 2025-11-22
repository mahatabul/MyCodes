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

    vector<ll> towers;

    for (ll i = 0; i < n; i++)
    {
        ll cube;
        cin >> cube;

        auto it = upper_bound(towers.begin(), towers.end(), cube);
        if (it == towers.end())
        {

            towers.push_back(cube);
        }
        else
        {

            *it = cube;
        }
    }

    cout << towers.size();
    return 0;
}
