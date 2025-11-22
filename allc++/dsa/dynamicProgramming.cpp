#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int MOD = 1e9 + 7;

long long topDownHelper(int n, vector<long long> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = (topDownHelper(n - 1, dp) + topDownHelper(n - 2, dp)) % MOD;
}

long long int topDown(int n)
{
    vector<long long> dp(n + 1, 0);
    return topDownHelper(n, dp);
}
long long int bottomUp(int n)
{
    // code here
    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        long long int curr = (prev2 + prev1) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int climbStairs(int n)
{

    if (n <= 2)
    {
        return n;
    }

    int pre1 = 1, pre2 = 2;

    for (int i = 3; i <= n; i++)
    {
        int curr = pre1 + pre2;
        pre1 = pre2;
        pre2 = curr;
    }

    return pre2;
}

#include <bits/stdc++.h>
// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     vector<int> dp(n + 1, -1);

//     dp[0] = 0;

//     for (int i = 1; i < n; i++)
//     {
//         int one = dp[i - 1] + abs(heights[i] - heights[i - 1]);
//         int two = INT_MAX;
//         if (i > 1)
//         {
//             /* code */
//             two = dp[i - 2] + abs(heights[i] - heights[i - 2]);
//         }

//         dp[i] = min(one, two);
//     }
//     return dp[n-1];
// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    int pre1 = 0;
    int pre2 = 0;

    for (int i = 1; i < n; i++)
    {

        int one = pre1 + abs(heights[i] - heights[i - 1]);
        int two = INT_MAX;
        if (i > 1)
        {
            two = pre2 + abs(heights[i] - heights[i - 2]);
        }

        int curr = min(one, two);

        pre2 = pre1;
        pre1 = curr;
    }

    return pre1;
}

int minimizeCost(int n, int k, vector<int> &height)
{
    // Write your code here.

    vector<int> dp(n, -1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                mini = min(mini, dp[i - j] + abs(height[i] - height[i - j]));
            }
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}
int rob1(vector<int> &nums)
{

    int pre2 = 0;
    int pre1 = nums[0];
    int take = 0, not_take = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        /* code */

        take = nums[i];
        if (i > 1)
        {
            take += pre2;
        }
        not_take = pre1;

        int curr = max(take, not_take);

        pre2 = pre1;
        pre1 = curr;
    }

    return pre1;
}

int rob(vector<int> &nums)
{

    if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> temp1(nums.begin() + 1, nums.end()), temp2(nums.begin(), nums.end() - 1);

    return max(rob1(temp1), rob1(temp2));
}

// int patH(int day, int col, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
// {
//     if (day == n)
//     {
//         return 0;
//     }
//     if (dp[day][col] != -1)
//     {
//         return dp[day][col];
//     }

//     int maximerit = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         if (i != col)
//         {
//             maximerit = max(maximerit, points[day][i] + patH(day + 1, i, n, points, dp));
//         }
//     }
//     return dp[day][col] = maximerit;
// }

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    for (int day = 1; day < n; day++)
    {
        for (int col = 0; col < 3; col++)
        {
            dp[day][col] = 0;
            for (int prevCol = 0; prevCol < 3; prevCol++)
            {
                if (prevCol != col)
                {
                    dp[day][col] = max(dp[day][col], points[day][col] + dp[day - 1][prevCol]);
                }
            }
        }
    }

    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

/* int solve(int i, int j, int m, int n, vector<vector<int>> &freq, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
    {

        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;

    int di[] = {1, 0};
    int dj[] = {0, 1};

    for (int idx = 0; idx < 2; idx++)
    {
        int ni = i + di[idx];
        int nj = j + dj[idx];

        if (ni < m && nj < n && !freq[ni][nj])
        {
            freq[ni][nj] = 1;
            ans += solve(ni, nj, m, n, freq, dp);
            freq[ni][nj] = 0;
        }
    }
    return dp[i][j] = ans;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> freq(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, -1));

    freq[0][0] = 1;
    int ans = solve(0, 0, m, n, freq, dp);
    return ans;
} */

/* int solve(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &og)
{
    if (i >= m || j >= n || og[i][j] == 1)
    {
        return 0;
    }
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    return dp[i][j] = solve(i + 1, j, m, n, dp, og) + solve(i, j + 1, m, n, dp, og);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
    {
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp, obstacleGrid);
} */

// int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
// {
//     int m = grid.size();
//     int n = grid[0].size();
//     if (i == m - 1 and j == n - 1)
//     {
//         return grid[i][j];
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }

//     int down = INT_MAX, right = INT_MAX;

//     if (i + 1 < m)
//     {
//         /* code */
//         down = solve(i + 1, j, grid, dp);
//     }
//     if (j + 1 < n)
//     {
//         /* code */
//         right = solve(i, j + 1, grid, dp);
//     }

//     return dp[i][j] = grid[i][j] + min(down, right);
// }

// int minPathSum(vector<vector<int>> &grid)
// {

//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));

//     return solve(0, 0, grid, dp);
// }

// int minimumTotalsolve(int row, int col, vector<vector<int>> &tri,vector<vector<int>> &dp)
// {
//     if (row == tri.size() - 1)
//     {

//         return tri[row][col];
//     }
//     if (dp[row][col]!=-1)
//     {
//         return dp[row][col];
//     }

//     int down = minimumTotalsolve(row + 1, col, tri,dp);

//     int dright = minimumTotalsolve(row + 1, col + 1, tri,dp);

//     return dp[row][col]= tri[row][col] + min(down, dright);
// }

// int minimumTotal(vector<vector<int>> &triangle)
// {

//     vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));

//     return minimumTotalsolve(0, 0, triangle,dp);
// }

/* int minFallingPathSumsolve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    if (row == mat.size() - 1)
    {
        return mat[row][col];
    }

    if (dp[row][col] != -101)
    {
        return dp[row][col];
    }

    int path1, path2, path3;
    path1 = path2 = path3 = INT_MAX;

    if (row + 1 < mat.size() and col + 1 < mat.size())
        path1 = minFallingPathSumsolve(row + 1, col + 1, mat, dp);

    if (row + 1 < mat.size() and col - 1 >= 0)
    {
        path2 = minFallingPathSumsolve(row + 1, col - 1, mat, dp);
    }

    if (row + 1 < mat.size())
    {
        path3 = minFallingPathSumsolve(row + 1, col, mat, dp);
    }

    return dp[row][col] = mat[row][col] + min({path1, path2, path3});
}

int minFallingPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, -101));

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, minFallingPathSumsolve(0, i, matrix, dp));
    }

    return ans;
}
 */
/*
int minFallingPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n, -101));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int row = 1; row < n; row++)

    {
        for (int col = 0; col < n; col++)
        {
            int path1, path2, path3;
            path1 = path2 = path3 = INT_MAX;

            if (row - 1 >= 0 and col - 1 >= 0)
                path1 = dp[row - 1][col - 1];

            if (row - 1 >= 0 and col + 1 < n)
            {
                path2 = dp[row - 1][col + 1];
            }

            if (row - 1 >= 0)
            {

                path3 = dp[row - 1][col];
            }

            dp[row][col] = matrix[row][col] + min({path1, path2, path3});
        }
    }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
 */
// int minFallingPathSum(vector<vector<int>> &matrix)
// {

//     int n = matrix.size();

//     vector<int> pre(n, -101);
//     vector<int> curr(n, -101);

//     for (int i = 0; i < n; i++)
//     {
//         pre[i] = matrix[0][i];
//     }

//     for (int row = 1; row < n; row++)

//     {
//         for (int col = 0; col < n; col++)
//         {
//             int path1, path2, path3;
//             path1 = path2 = path3 = INT_MAX;

//             if (col - 1 >= 0)
//                 path1 = pre[col - 1];

//             if (col + 1 < n)
//             {
//                 path2 = pre[col + 1];
//             }

//             path3 = pre[col];

//             curr[col] = matrix[row][col] + min({path1, path2, path3});
//         }

//         pre = curr;
//     }

//     return *min_element(pre.begin(), pre.end());
// }

// int solve(int n, int m, vector<vector<int>> &grid) {

//     vector<vector<int>> front(m, vector<int>(m, 0));
//     vector<vector<int>> cur(m, vector<int>(m, 0));

//     for (int j1 = 0; j1 < m; j1++) {
//         for (int j2 = 0; j2 < m; j2++) {
//             if (j1 == j2)
//                 front[j1][j2] = grid[n - 1][j1];
//             else
//                 front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
//         }
//     }

//    for (int i = n - 2; i >= 0; i--) {
//         for (int j1 = 0; j1 < m; j1++) {
//             for (int j2 = 0; j2 < m; j2++) {
//                 int maxi = INT_MIN;

//                for (int di = -1; di <= 1; di++) {
//                     for (int dj = -1; dj <= 1; dj++) {
//                         int ans;

//                         if (j1 == j2)
//                             ans = grid[i][j1];
//                         else
//                             ans = grid[i][j1] + grid[i][j2];

//                         if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
//                             ans += -1e9;
//                         else
//                             ans += front[j1 + di][j2 + dj];

//                         maxi = max(ans, maxi);
//                     }
//                 }
//                 cur[j1][j2] = maxi;
//             }
//         }
//         front = cur;  }

//    return front[0][m - 1];
// }

bool isSubsetSum(vector<int> &arr, int target)
{
    vector<bool> pre(target + 1, false), curr(target + 1, false);

    pre[0] = curr[0] = true;

    if (arr[0] <= target)
        pre[arr[0]] = true;

    for (int idx = 1; idx < arr.size(); idx++)
    {
        for (int i = 1; i <= target; i++)
        {
            bool not_take = pre[i];
            bool take = false;
            if (arr[idx] <= i)
            {
                take = pre[i - arr[idx]];
            }
            curr[i] = not_take || take;
        }
        pre = curr;
    }

    return pre[target];
}
// bool canPartition(vector<int> &nums)
// {

//     long int target = accumulate(nums.begin(), nums.end(), 0);
//     if (target % 2 != 0)
//     {
//         return false;
//     }
//     target /= 2;

//     return isSubsetSum(nums, target);
// }

// int minimumDifference(vector<int> &nums)
// {

//     int n = nums.size();
//     int tsum = accumulate(nums.begin(), nums.end(), 0);

//     vector<vector<bool>> dp(n, vector<bool>(tsum+1, false));

//     for (int i = 0; i < n; i++)
//     {
//         dp[i][0] = true;
//     }

//     if (nums[0] >= 0 and nums[0] <= tsum)
//     {
//         dp[0][nums[0]] = true;
//     }

//     for (int idx = 1; idx < n; idx++)
//     {
//         for (int i = 1; i <= tsum; i++)
//         {
//             bool not_take = dp[idx - 1][i];

//             bool take = false;

//             if (nums[idx] <= i)
//             {
//                 take = dp[idx - 1][i - nums[idx]];
//             }

//             dp[idx][i] = take or not_take;
//         }
//     }
//     int ans = INT_MAX;

//     for (int i = 0; i < tsum; i++)
//     {
//         if (dp[n - 1][i])
//         {
//             int s1 = i, s2 = tsum - i;

//             ans = min(ans, abs(s1 - s2));
//         }
//     }

//     return ans;
// }

int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    int tsum = accumulate(nums.begin(), nums.end(), 0);

    int target = tsum;

    vector<bool> prev(target + 1, false);
    prev[0] = true;

    if (nums[0] >= 0 && nums[0] <= target)
    {
        prev[nums[0]] = true;
    }

    for (int idx = 1; idx < nums.size(); idx++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;

        for (int i = 1; i <= target; i++)
        {
            bool not_take = prev[i];
            bool take = false;

            if (nums[idx] <= i)
            {
                take = prev[i - nums[idx]];
            }

            curr[i] = take || not_take;
        }
        prev = curr;
    }

    int ans = INT_MAX;

    for (int s1 = 0; s1 <= target; s1++)
    {
        if (prev[s1])
        {
            int s2 = tsum - s1;
            ans = min(ans, abs(s1 - s2));
        }
    }

    return ans;
}

// int solving(int index, vector<int> &nums, int s, int target, vector<vector<int>> &dp)
// {
//     if (index == nums.size())
//     {
//         return s == target ? 1 : 0;
//     }
//     if (dp[index][s] != -1)
//     {
//         return dp[index][s];
//     }

//     int l = solving(index + 1, nums, s + nums[index], target, dp);

//     int r = solving(index + 1, nums, s, target, dp);

//     return dp[index][s] = l + r;
// }

// int perfectSum(vector<int> &arr, int target)
// {
//     vector<int> pre(target + 1, 0), curr(target + 1, 0);

//     pre[0] = curr[0] = 1;

//     if (arr[0] <= target)
//     {
//         pre[arr[0]] += 1;
//     }

//     for (int idx = 1; idx < arr.size(); idx++)
//     {
//         for (int i = 0; i <= target; i++)
//         {
//             int not_take = pre[i];
//             int take = 0;
//             if (arr[idx] <= i)
//             {
//                 take = pre[i - arr[idx]];
//             }
//             curr[i] = not_take + take;
//         }
//         pre = curr;
//     }

//     return pre[target];
// }

// int countPartitions(vector<int>& nums, int d) {
//     // Code here

//     int tsum = accumulate(nums.begin(),nums.end(),0);

//     int target = (tsum-d);

//     if (target<0 or target%2==1)
//     {
//         return 0;
//     }

//     return perfectSum(nums,target/2);

// }

/*
int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // code here
    vector<int> pre(capacity + 1, 0);

    for (int i = wt[0]; i <= capacity; i++)
    {
        pre[i] = val[0];
    }

    for (int i = 1; i < val.size(); i++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int not_take = pre[w];
            int take = INT_MIN;
            if (wt[i] <= w)
            {
                take = val[i] + pre[w - wt[i]];
            }
            pre[w] = max(not_take, take);
        }
    }
    return pre[capacity];
} */

/* int coinChangesolve(int idx, int target, vector<int> &coins, vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (target % coins[0] == 0)
        {
            return target / coins[0];
        }
        return 1e9;
    }

    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }

    int not_take = coinChangesolve(idx - 1, target, coins, dp);
    int take = 1e9;

    if (coins[idx] <= target)
    {
        take = 1 + coinChangesolve(idx, target - coins[idx], coins, dp);
    }

    return dp[idx][target] = min(take, not_take);
} */

// int coinChange(vector<int> &coins, int amount)
// {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

//     for (int i = 0; i <= amount; i++)
//     {
//         if (i % coins[0] == 0)
//         {
//             /* code */
//             dp[0][i] = i / coins[0];
//         }
//         else
//         {
//             dp[0][i] = 1e9;
//         }
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int target = 0; target <= amount; target++)
//         {
//             int not_take = dp[i - 1][target];
//             int take = 1e9;
//             if (coins[i] <= target)
//             {
//                 take = 1 + dp[i][target - coins[i]];
//             }
//             dp[i][target] = min(take, not_take);
//         }
//     }

//     int ans = dp[n - 1][amount];
//     if (ans >= 1e9)
//     {
//         return -1;
//     }

//     return ans;
// }
/*
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> pre(amount + 1, 1e9);

    pre[0] = 0;

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            pre[i] = i / coins[0];
        }
    }

    for (int i = 1; i < n; i++)
    {

        for (int target = 0; target <= amount; target++)
        {
            int not_take = pre[target];
            int take = 1e9;
            if (coins[i] <= target)
            {
                take = 1 + pre[target - coins[i]];
            }
            pre[target] = min(take, not_take);
        }
    }

    int ans = pre[amount];
    return (ans >= 1e9) ? -1 : ans;
}
 */

// int changeSolve(int idx, int amount, vector<int> &coins)
// {

//     if (idx == 0)
//     {
//         if (coins[0] == amount or amount % coins[0] == 0)
//         {
//             return 1;
//         }
//         return 0;
//     }

//     int not_take = changeSolve(idx - 1, amount, coins);
//     int take = 0;

//     if (coins[idx] <= amount)
//     {
//         /* code */
//         take = changeSolve(idx, amount - coins[idx], coins);
//     }

//     return take + not_take;
// }
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<long long>pre(amount+1);
//     for(int i=0;i<=amount;i++){
//         if(i % coins[0] == 0){
//             pre[i] = 1;
//         }
//     }
//     for(int i=1;i<n;i++){
//         vector<long long>curr(amount+1);
//         for(int j=0;j<=amount;j++){
//             int Take  = 0;
//             if(coins[i] <= j){
//                 Take  = curr[j-coins[i]];
//             }
//             int notTake  = pre[j];
//             curr[j] = (long)Take +notTake ;
//         }
//         pre = curr;
//     }
//     return pre[amount];
// }

/* int knapSackSolve(int idx, vector<int> &val, vector<int> &wt, int capacity,vector<vector<int>>&dp)
{
    if (idx == 0)
    {
        return ((int)(capacity / wt[0])) * val[0];
    }
    if (dp[idx][capacity]!=-1)
    {
        return dp[idx][capacity];
    }


    int notTake = knapSackSolve(idx - 1, val, wt, capacity,dp);
    int Take = 0;
    if (wt[idx] <= capacity)
    {
        Take = val[idx] + knapSackSolve(idx, val, wt, capacity - wt[idx],dp);
    }

    return dp[idx][capacity]=max(notTake , Take);
}
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
    return knapSackSolve(n - 1, val, wt, capacity,dp);
}
 */
/*
int cutRodsolve(int idx, int n, vector<int> &price, vector<vector<int>> &dp)
{
    // code here

    if (idx == 0)
    {


        return n * price[0];
    }
    if (dp[idx][n] != -1)
    {
        return dp[idx][n];
    }

    int not_cut = cutRodsolve(idx - 1, n, price, dp);

    int cut = 0;

    if (idx + 1 <= n)
    {

        cut = price[idx] + cutRodsolve(idx, n - (idx + 1), price, dp);
    }

    return dp[idx][n] = max(cut, not_cut);
}
 */
/* int cutRod(vector<int> &price)
{
    // code here
    int n = price.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int j = 0; j <= n; j++)
        {
            int not_cut = dp[idx - 1][j];

            int cut = 0;

            if (idx + 1 <= j)
            {

                cut = price[idx] + dp[idx][j - (idx + 1)];
            }
            dp[idx][j] = max(cut, not_cut);
        }
    }

    return dp[n - 1][n];
} */

/* int longestCommonSubsequenceSolve(int idx1, int idx2, string t1, string t2, vector<vector<int>> &dp)
{
    if (idx1 == 0 or idx2 == 0)
    {
        return 0;
    }
    if (dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }

    if (t1[idx1 - 1] == t2[idx2 - 1])
    {
        return dp[idx1][idx2] = 1 + longestCommonSubsequenceSolve(idx1 - 1, idx2 - 1, t1, t2, dp);
    }

    return dp[idx1][idx2] = max(longestCommonSubsequenceSolve(idx1 - 1, idx2, t1, t2, dp), longestCommonSubsequenceSolve(idx1, idx2 - 1, t1, t2, dp));
} */

/*


string findLCS(int n, int m, string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    int len = dp[n][m];

    int index = len - 1;
    string str = "";
    for (int i = 1; i <= len; i++)
    {
        str[i] += '#';
    }

    int i = n - 1, j = m - 1;

    while (i > 0 and j > 0)
    {
        if (s1[i] == s2[j])
        {
            str[index] = s1[i];
            index--;
            i--;
            j--;
        }
        else if (s1[i - 1] > s2[j - 1])
        {
            i--;
        }
        else
            j--;
    }

    return str;
} */
/*
int longestCommonSubstr(string &t1, string &t2)
{
    // your code here
    int n = t1.size();
    int m = t2.size();

    vector<int> pre(m + 1, 0);
    vector<int> cur(m + 1, 0);
    int ans = 0;

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            if (t1[idx1 - 1] == t2[idx2 - 1])
            {
                cur[idx2] = 1 + pre[idx2 - 1];
                ans = max(ans, cur[idx2]);
            }

            else
                cur[idx2] = 0;
        }
        pre = cur;
    }
    return ans;
}

int longestCommonSubsequence(string t1, string t2) {
    int n = t1.size();
    int m = t2.size();

    vector<int> pre(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int idx1 = 1; idx1 <= n; idx1++) {
        for (int idx2 = 1; idx2 <= m; idx2++) {
            if (t1[idx1 - 1] == t2[idx2 - 1]) {
                cur[idx2] = 1 + pre[idx2 - 1];
            } else {
                cur[idx2] = max(cur[idx2 - 1], pre[idx2]);
            }
        }
        pre = cur;
    }

    return pre[m];
}

int longestPalindromeSubseq(string s) {
    string s2 = s;
    reverse(s2.begin(), s2.end());

    return longestCommonSubsequence(s, s2);
}
int minInsertions(string s) {
    int n = s.size();
    return n - longestPalindromeSubseq(s);
}

 */
/*
int longestCommonSubsequence(string t1, string t2)
{
    int n = t1.size();
    int m = t2.size();

    vector<int> pre(m + 1, 0);
    vector<int> cur(m + 1, 0);

    for (int idx1 = 1; idx1 <= n; idx1++)
    {
        for (int idx2 = 1; idx2 <= m; idx2++)
        {
            if (t1[idx1 - 1] == t2[idx2 - 1])
            {
                cur[idx2] = 1 + pre[idx2 - 1];
            }
            else
            {
                cur[idx2] = max(cur[idx2 - 1], pre[idx2]);
            }
        }
        pre = cur;
    }

    return pre[m];
}
int minDistance(string word1, string word2)
{

    int j = longestCommonSubsequence(word1, word2);

    return (word1.size() + word2.size()) - 2 * j;
}

int numDistinctsolve(int i, int j, string &s, string &t,
                     vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
    {
        return dp[i][j] = numDistinctsolve(i - 1, j - 1, s, t, dp) +
                          numDistinctsolve(i - 1, j, s, t, dp);
    }
    return dp[i][j] = numDistinctsolve(i - 1, j, s, t, dp);
}

const int prime = 1e9 + 7;
int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> prev(m + 1, 0);

    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {  if (s[i - 1] == t[j - 1])
            {
                prev[j] = (prev[j - 1] + prev[j]);
            }
        }
    }

    return prev[m];
}
 */


int minDistance(string word1, string word2)
{

    int n = word1.size();
    int m = word2.size();

    vector<int>pre(m+1,0);
    vector<int>curr(m+1,0);

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
    {
        pre[0] = i;
    }
   

    for (int i = 1; i <= n; i++)
    {
        curr[0]=i;
        for (int j = 1; j <= m; j++)
        {
            if (word1[i] == word2[j])
            {
                curr[j] = pre[j - 1];
            }
            else
            {
                curr[j] = 1 + min({pre[j], curr[j - 1], pre[j - 1]});
            }
        }
        pre=curr;
    }

    return pre[m];
}
int main()
{

    return 0;
}
