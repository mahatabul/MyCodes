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

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        set<ll> arr;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr.insert(a);
        }
        vector<ll> ans(arr.begin(), arr.end());

        int a = ans.back();
        ans.pop_back();
        int b = ans.back();
        cout << a + b << endl;
    }

    return 0;
}