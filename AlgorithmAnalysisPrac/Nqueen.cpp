#include <bits/stdc++.h>
using namespace std;

vector<int> upDiagonalMap(2 * 100 - 1, 0);
vector<int> downDiagonalMap(2 * 100 - 1, 0);
vector<int> rowMap(100, 0);

bool isSafe(int row, int col, int n)
{
    if (rowMap[row] or downDiagonalMap[row + col] or upDiagonalMap[(n - 1) + (col - row)])
    {
        return false;
    }
    return true;
}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 'Q';
            rowMap[row] = downDiagonalMap[row + col] = upDiagonalMap[(n - 1) + (col - row)] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = '.';
            rowMap[row] = downDiagonalMap[row + col] = upDiagonalMap[(n - 1) + (col - row)] = 0;
        }
    }
}
vector<vector<string>> Nqueen(int n)
{
    upDiagonalMap.resize(2 * n - 1);
    downDiagonalMap.resize(2 * n - 1);
    rowMap.resize(n);
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, ans, board, n);

    return ans;
}
int main()
{
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<string>> solutions = Nqueen(n);

    cout << "Total solutions = " << solutions.size() << endl << endl;

    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (auto &row : solutions[i])
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
