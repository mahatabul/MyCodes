#include <bits/stdc++.h>
using namespace std;

// memoization (topdown)
/* int knaprecur(int i, vector<int> &wt, vector<int> &val, int capacity, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[0] <= capacity)
            return val[0];
        return 0;
    }
    if (dp[i][capacity] != -1)
    {
        return dp[i][capacity];
    }

    int take = INT_MIN, nottake;
    if (wt[i] <= capacity)
    {
        take = val[i] + knaprecur(i - 1, wt, val, capacity - wt[i], dp);
    }
    nottake = knaprecur(i - 1, wt, val, capacity, dp);

    return dp[i][capacity] = max(take, nottake);
}

int knapsack(vector<int> &wt, vector<int> &val, int capacity)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return knaprecur(n - 1, wt, val, capacity, dp);
}
 */

// tabulation (bottomup)
int knapsack(vector<int> &wt, vector<int> &val, int capacity)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int i = wt[0]; i <= capacity; i++)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int take = INT_MIN, nottake;
            if (wt[i] <= j)
            {
                take = val[i] + dp[i - 1][j - wt[i]];
            }
            nottake = dp[i - 1][j];

            dp[i][j] = max(take, nottake);
        }
    }

    return dp[n - 1][capacity];
}
int main()
{

    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};

    cout << knapsack(wt, val, 6);
    return 0;
}