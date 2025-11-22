#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getTotalLines(ll v, ll k) {
    ll total = 0;
    while (v > 0) {
        total += v;
        v /= k;
    }
    return total;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    ll left = 1, right = n;
    ll ans = n;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (getTotalLines(mid, k) >= n) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}