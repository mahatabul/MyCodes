#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

void ratinmaze(int i, int j, vector<vector<char>> &mat, vector<string> &ans, string s, int row, int col, vector<vector<int>> &freq)
{
    if (i == row - 1 && j == col - 1)
    {
        ans.push_back(s);
        return;
    }

    string dir = "DR";
    int di[] = {1, 0};
    int dj[] = {0, 1};

    for (int idx = 0; idx < 2; idx++)
    {
        int ni = i + di[idx];
        int nj = j + dj[idx];

        if (ni >= 0 && nj >= 0 && ni < row && nj < col && !freq[ni][nj] && mat[ni][nj] == '.')
        {
            freq[ni][nj] = 1;
            ratinmaze(ni, nj, mat, ans, s + dir[idx], row, col, freq);
            freq[ni][nj] = 0;
        }
    }
}

vector<string> findPath(vector<vector<char>> &mat)
{
    vector<string> ans;
    string s = "";
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> freq(row, vector<int>(col, 0));

    if (mat[0][0] == '.')
    {
        freq[0][0] = 1;
        ratinmaze(0, 0, mat, ans, s, row, col, freq);
    }

    return ans;
}
int main()
{
    fastio;

    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h,vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<string> anS = findPath(grid);

    int ans = anS.size();

    cout << ans << "\n";

    return 0;
}