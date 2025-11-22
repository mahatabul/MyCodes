#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int summation(vector<int> vec, int n)
{
    if (n == 0)
    {
        return vec[0];
    }

    return vec[n] + summation(vec, n - 1);
}
int main()
{
    fastio;

    int t, c = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> k;

        for (int i = 0; i < n; i++)
        {
            /* code */
            int a;
            cin >> a;
            k.push_back(a);
        }
        cout << "Case " << c << ": " << summation(k, n - 1) << "\n";
        c++;
    }

    return 0;
}