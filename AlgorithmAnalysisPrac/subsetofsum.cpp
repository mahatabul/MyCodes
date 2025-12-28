#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void sumOfSubsets(int idx, int currSum, int target,
                  vector<int> &arr, vector<int> &subset)
{
    // If target sum reached
    if (currSum == target)
    {
        ans.push_back(subset);
        return;
    }

    // If exceeded target or no more elements
    if (idx == arr.size() || currSum > target)
        return;

    // Include current element
    subset.push_back(arr[idx]);
    sumOfSubsets(idx + 1, currSum + arr[idx], target, arr, subset);
    subset.pop_back();

    // Exclude current element
    sumOfSubsets(idx + 1, currSum, target, arr, subset);
}

int main()
{
    vector<int> arr = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;

    vector<int> subset;
    cout << "Subsets with sum " << target << ":\n";
    sumOfSubsets(0, 0, target, arr, subset);
    for (auto it : ans)
    {
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
