#include <bits/stdc++.h>
using namespace std;

// memoization
/*
int mcm(vector<int> arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int minCost = INT_MAX;
    for (int k = i; k < j; k++)
    {
        minCost = min(minCost, arr[i - 1] * arr[k] * arr[j] + mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp));
    }
    return dp[i][j] = minCost;
}
int matrixchain(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return mcm(arr, 1, n - 1, dp);
}
 */

// tabulation method
int matrixchain(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int minCost = INT_MAX;

            for (int k = i; k < j; k++)
            {
                minCost = min(minCost, arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = minCost;
        }
    }

    return dp[1][n - 1];
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 30};
    cout << matrixchain(arr);
    return 0;
}