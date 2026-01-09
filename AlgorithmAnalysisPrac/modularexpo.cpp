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
    
    // Decrease by 1: a^n = a * a^(n-1)
    ll result = modExp(a, n - 1);
    result = (result * a) % MOD;
    
    return result;
}

int main()
{
    long long a = 3, n = 13;
    cout << modExp(a, n) << endl;

    return 0;
}