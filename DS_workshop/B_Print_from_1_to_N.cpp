#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

void recur(int s, int n)
{

    if (s > n)
    {
        /* code */
        return;
    }
    cout << s << endl;

    recur(++s,n);
}
int main()
{
    fastio;

    int n;
    cin >> n;

    recur(1, n);

    return 0;
}