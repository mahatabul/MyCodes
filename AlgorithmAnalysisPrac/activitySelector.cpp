#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long

bool compare(pair<int, int> it1, pair<int, int> it2)
{
    return it1.second < it2.second;
}
int activitySelector(vector<int> start, vector<int> finish)
{
    vector<pair<int, int>> ac;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        ac.push_back({start[i], finish[i]});
    }
    sort(ac.begin(), ac.end(), compare);

    int count = 1;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (ac[i].first > ac[j].second)
        {
            count++;
            j = i;
        }
    }

    return count;
}

int main()
{
    fast_io;

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelector(start, finish);

    return 0;
}