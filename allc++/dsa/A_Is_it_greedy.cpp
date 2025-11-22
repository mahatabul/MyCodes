#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

int main()
{
    
    fastio;

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<ll, ll> mp;
    mp[0]++;
    ll sum = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        count += mp[sum - x];

        mp[sum]++;
    }
    cout << count << endl;

    return 0;
}
