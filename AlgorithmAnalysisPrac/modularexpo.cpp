#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll modExp(ll a, ll n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    // if n is even
    ll half = modExp(a, n / 2);
    ll result = (half * half) % MOD;

    // if n is odd
    if (n & 1)
    {
        result *= a;
        result %= MOD;
    }

    return result;
}

int main()
{
    long long a = 3, n = 13;
    cout << modExp(a, n) << endl;

    return 0;
}
