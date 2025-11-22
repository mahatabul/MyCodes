#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0, content = 0;

    while (i < g.size() and j < s.size())
    {
        if (s[j] >= g[i])
        {
            content++;
            i++;
        }
        j++;
    }

    return i;
}

bool lemonadeChange(vector<int> &bills)
{
    int cash = 0, change;
    map<int, int> hp;
    hp[0] = 1;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            hp[5]++;
        }
        else if (bills[i] == 10)
        {
            if (hp[5] == 0)
            {
                return false;
            }
            hp[5]--;
            hp[10]++;
        }
        else if (bills[i] == 20)
        {
            if (hp[10] > 0 && hp[5] > 0)
            {
                hp[10]--;
                hp[5]--;
            }
            else if (hp[5] >= 3)
            {
                hp[5] -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

long long solve(vector<int> &bt)
{
    // code here
    sort(bt.begin(), bt.end());
    long t = 0, time = 0, n = bt.size();

    for (int i = 0; i < n; i++)
    {
        time += t;
        t += bt[i];
    }

    return time / n;
}
bool canJump(vector<int> &nums)
{

    int i = 0, maxindex = 0;

    while (i < nums.size())
    {
        if (i > maxindex)
        {
            return false;
        }

        maxindex = max(maxindex, i + nums[i]);
        i++;
    }
    return true;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;

    int jumps = 0, currentEnd = 0, farthest = 0;

    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);

        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1)
            {
                break;
            }
        }
    }

    return jumps;
}

int maxDifference(string s)
{

    int even = INT_MAX, odd = INT_MIN;
    map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second & 1)
        {
            odd = max(odd, it.second);
        }
        else
            even = min(even, it.second);
    }

    return (odd - even);
}

struct Jobs
{
    int Id;
    int deadline;
    int profit;
};
static bool comparator(Jobs a, Jobs b)
{
    return a.profit > b.profit;
}
vector<int> solve(vector<Jobs> a, int maximumdeadline)
{
    sort(a.begin(), a.end(), comparator);
    int maximumProfit = 0, maximumJobs = 0;
    vector<int> hmap(maximumdeadline + 1, -1);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = a[i].deadline; j > 0; j--)
        {
            if (hmap[j] == -1)
            {
                hmap[j] = a[i].Id;
                maximumProfit += a[i].profit;
                maximumJobs++;
                break;
            }
        }
    }

    return {maximumJobs, maximumProfit};
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                          vector<int> &profit)
{
    vector<Jobs> a(id.size());
    int maximumdeadline = -1;

    for (int i = 0; i < id.size(); i++)
    {
        a[i].Id = id[i];
        a[i].deadline = deadline[i];
        a[i].profit = profit[i];
        maximumdeadline = max(maximumdeadline, deadline[i]);
    }

    return solve(a, maximumdeadline);
}
struct Meeting
{
    int start, end, duration;
};

int solvefunction(vector<Meeting> m)
{
    int ans = 1;

    sort(m.begin(), m.end(), [](Meeting m1, Meeting m2)
         { return m1.end < m2.end; });

    //  for(auto it:m){
    //     cout<<it.start<<" "<<it.end<<"\n";
    //  }

    int endTime = m[0].end;

    // cout<<m[0].start<<" "<<m[0].end<<"\n";

    for (int i = 1; i < m.size(); i++)
    {
        if (m[i].start > endTime)
        {
            ans++;
            endTime = m[i].end;
            // cout<<m[i].start<<" "<<m[i].end<<"\n";
        }
    }

    return ans;
}
int maxMeetings(vector<int> &start, vector<int> &end)
{
    // Your code here

    vector<Meeting> m(start.size());

    for (int i = 0; i < start.size(); i++)
    {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].duration = abs(start[i] - end[i]);
    }

    return solvefunction(m);
}

struct Interval
{
    int start, end;
};
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int ans = 0;
    int endTime = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < endTime)
        {
            ans++;
        }
        else
        {
            endTime = intervals[i][1];
        }
    }

    return ans;
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{

    int newStart = newInterval[0], newEnd = newInterval[1], n = intervals.size();

    vector<vector<int>> ans;

    int i = 0;
    while (i < n and intervals[i][1] < newStart)
    {
        ans.push_back({intervals[i][0], intervals[i][1]});
        i++;
    }

    while (i < n and intervals[i][0] <= newEnd)
    {
        newStart = min(intervals[i][0], newStart);
        newEnd = max(intervals[i][1], newEnd);
        i++;
    }
    ans.push_back({newStart, newEnd});

    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 1, j = 0, cnt = 1, maxCnt = 1;
    while (i < arr.size() and j < dep.size())
    {
        if (dep[j] < arr[i])
        {
            cnt--;
            j++;
        }
        else
        {
            cnt++;
            i++;
        }
        maxCnt = max(cnt, maxCnt);
    }

    return maxCnt;
}

bool checkValidString(string s)
{
    stack<int> st;
    stack<int> asterick;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == '*')
        {
            asterick.push(i);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else if (!asterick.empty())
            {
                asterick.pop();
            }
            else
            {
                return false;
            }
        }
    }

    while (!asterick.empty() and !st.empty())
    {
        if (st.top() < asterick.top())
        {
            st.pop();
            asterick.pop();
        }
        else
        {
            break;
        }
    }

    return st.empty();
}

int candy(vector<int> &ratings)
{

    int n = ratings.size();
    if (n == 1)
        return 1;

    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int totalCandies = 0;
    for (auto c : candies)
    {
        totalCandies += c;
    }

    return totalCandies;
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    // Your code here

    double ans = 0.0;

    vector<pair<double, int>> v;
    double capacitycopy = capacity;

    for (int i = 0; i < val.size(); i++)
    {
        double ratio = ((double)val[i] / (double)wt[i]);

        v.push_back({ratio, i});
    }

    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int index = v[i].second;
        double value = val[index], weight = wt[index];

        if (weight <= capacitycopy)
        {
            ans += value;
            capacitycopy -= weight;
        }
        else
        {
            ans += (v[i].first) * capacitycopy;
            break;
        }
    }

    return ans;
}
int main()
{

    vector<int> val, wt;
    val = {8, 2, 10, 1, 9, 7, 2, 6, 4, 9};
    wt = {10, 1, 7, 7, 5, 1, 8, 6, 8, 7};

    // vector<pair<double, double>> items;

    // for (int i = 0; i < val.size(); i++)
    // {
    //     items.push_back({wt[i], val[i]});
    // }

    // sort(items.begin(), items.end());

    // for (int i = 0; i < items.size(); i++)
    // {
    //     cout << items[i].first << " " << items[i].second << "\n";
    // }

    cout << setprecision(6) << fixed << fractionalKnapsack(val, wt, 21);

    return 0;
}