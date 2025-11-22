#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

bool canProduce(vector<ll> &machines, ll n, ll t, ll time)
{
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += time / machines[i];
        if (ans >= t)
        {
            return true;
        }
    }
    return ans >= t;
}
int main()
{
    fastio;

    ll n, t, result;
    cin >> n >> t;

    vector<ll> machines(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> machines[i];
    }

    ll l = 1, r = *max_element(machines.begin(), machines.end()) * t;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (canProduce(machines, n, t, mid))
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}