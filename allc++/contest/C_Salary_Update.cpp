#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int MAXN = 2e5 + 5;
vector<int> bit(MAXN);

void bitupdate(int idx, int val)
{
    while (idx < MAXN)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int qsolve(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        bitupdate(a[i], 1);
    }

    while (q--)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            int k, x;
            cin >> k >> x;
            k--;
            bitupdate(a[k], -1);
            a[k] = x;
            bitupdate(x, 1);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << qsolve(b) - qsolve(a - 1) << '\n';
        }
    }
    return 0;
}