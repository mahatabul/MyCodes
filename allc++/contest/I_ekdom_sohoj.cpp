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
        int n;
        cin >> n;
        int a = 0;

        vector<vector<int>> arr(n, vector<int>(n, 0));

        arr[0][0] = 1;
        arr[n - 1][n - 1] = n * n;

        int row = 0;
        int d = 1;
        for (int i = 1; i < n; i++)
        {

            arr[row][i] = d + arr[row][i - 1];
            d++;
        }
        int col = 0;
        d = 2;
        for (int i = 1; i < n; i++)
        {

            arr[i][0] = d + arr[i - 1][0];
            d++;
        }
        d--;

        for (int i = 1; i < n - 1; i++)
        {

            arr[i][n - 1] = d + arr[i - 1][n - 1];
            d--;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (arr[i][j] == 0)
                {
                    arr[i][j] = arr[i - 1][j + 1] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}