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

    int n;
    cin >> n;
    int ans = 0;
    if (n >= 1)
    {
        n -= 1;
        ans++;
    }
    if (n >= 2)
    {
        n -= 2;
        ans++;
    }
    if (n >= 4)
    {
        n -= 4;
        ans++;
    }

    cout << ans << endl;

    return 0;
}