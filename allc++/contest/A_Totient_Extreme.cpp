/*
C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do, it blows your whole leg off.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
#define ll long long
#define ul unsigned ll
#define pb push_back
#define mp make_pair
#define bend(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

vector<ll> totient;

void compute_totients(int n) {
    totient.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        totient[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (totient[i] == i) {
            for (int j = i; j <= n; j += i) {
                totient[j] = totient[j] * (i - 1) / i;
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;

    compute_totients(n);

    ll h = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            h += totient[i] * totient[j];
        }
    }

    cout << h << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}