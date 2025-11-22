#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

ll solve(ll n)
{

    if (n == 0)
    {
        return 1;
    }
    return n * solve(n - 1);
}

int main()
{
    fastio;
    int n;
    cin>>n;
    cout << solve(n) << "\n"; 

    return 0;
}