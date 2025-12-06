#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long

// memoization
/* int LCSrecur(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + LCSrecur(i - 1, j - 1, s1, s2, dp);
    }

    return dp[i][j] = max(LCSrecur(i - 1, j, s1, s2, dp), LCSrecur(i, j - 1, s1, s2, dp));
} */

// tabulation
/* int LCS(string &s1, string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n1][n2];
} */
// memoization (top-down) returns LCS string
/* string LCSrecur(int i, int j, string &s1, string &s2, vector<vector<string>> &dp)
{
    if (i < 0 or j < 0)
    {
        return "";
    }
    if (dp[i][j] != "#")
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        return dp[i][j] = s1[i] + LCSrecur(i - 1, j - 1, s1, s2, dp);
    }
    else
    {
        string up = LCSrecur(i - 1, j, s1, s2, dp);
        string down = LCSrecur(i, j - 1, s1, s2, dp);
        if (up.length() > down.length())
        {
            dp[i][j] = up;
        }
        else
        {
            dp[i][j] = down;
        }
    }

    return dp[i][j];
}
string LCS(string &s1, string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<string>> dp(n1, vector<string>(n2, "#"));
    string ans = LCSrecur(n1 - 1, n2 - 1, s1, s2, dp);
    reverse(ans.begin(), ans.end());
    return ans;
} */

// tabulation (returns the LCS string)
string LCS(string &s1, string &s2)
{
    string ans = "";
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {

                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len = dp[n1][n2];
    ans.resize(len);

    int idx = len - 1;
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[idx] = s1[i - 1];
            idx--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }

    return ans;
}
int main()
{
    fast_io;
    string ans;

    // Test case 1
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";
    cout << "Test Case 1:" << endl;
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Expected LCS Length: 4 (e.g., \"BCAB\")" << endl;

    cout << "Output: " << LCS(s1, s2) << endl
         << endl;

    // Test case 2
    s1 = "XMJYAUZ";
    s2 = "MZJAWXU";
    cout << "Test Case 2:" << endl;
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Expected LCS Length: 4 (e.g., \"MJAU\")" << endl;
    cout << "Output: " << LCS(s1, s2) << endl
         << endl;

    // Test case 3 (Edge case: No common subsequence)
    s1 = "ABC";
    s2 = "DEF";
    cout << "Test Case 3:" << endl;
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Expected LCS Length: 0" << endl;
    cout << "Output: " << LCS(s1, s2) << endl
         << endl;

    // Test case 4 (Edge case: Identical strings)
    s1 = "HELLO";
    s2 = "HELLO";
    cout << "Test Case 4:" << endl;
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"" << endl;
    cout << "Expected LCS Length: 5" << endl;
    cout << "Output: " << LCS(s1, s2) << endl
         << endl;

    return 0;
}