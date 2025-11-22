#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                   \
    cout.tie(0);

ll binary(vector<ll> a, ll low, ll high, ll el)
{
    if (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (a[mid] < el)
            return binary(a, mid + 1, high, el);
        else if (a[mid] > el)
            return binary(a, low, mid - 1, el);
        else
            return mid;
    }
    return 0;
}

void func(vector<ll> &a, ll el, ll newel)
{
    sort(a.begin(), a.end());
    ll idx = binary(a, 0, a.size(), el);
    a[idx] = newel;
}

int main()
{
    fastio;
    ll n;
    cin >> n;
    vector<ll> arr(n), tower;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    tower.push_back(arr[0]);
    ll maxi = arr[0];
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            tower.push_back(arr[i]);
            maxi = arr[i];
        }
        else
        {
            sort(tower.begin(),tower.end());
            ll el = *upper_bound(tower.begin(), tower.end(), arr[i]);
            func(tower, el, arr[i]);
            maxi = *max_element(tower.begin(), tower.end());
        }
    }
    cout << tower.size();
    return 0;
}