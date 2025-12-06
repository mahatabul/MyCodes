#include <bits/stdc++.h>
using namespace std;

int fracKnapsack(vector<int> &wt, vector<int> &val, int W)
{
    int ans = 0;
    vector<tuple<double, int, int>> profit;
    for (int i = 0; i < wt.size(); i++)
    {
        double p = (double)val[i] / (double)wt[i];
        profit.push_back({p, val[i], wt[i]});
    }

    sort(profit.begin(), profit.end(), [](auto &a, auto &b)
         { return get<0>(a) >= get<0>(b); });

    for (const auto &it : profit)
    {
        double pft = get<0>(it);
        int vall = get<1>(it);
        int wtt = get<2>(it);
        if (W >= wtt)
        {
            ans += vall;
            W -= (wtt);
        }
        else
        {
            ans += pft * W;
            break;
        }
    }
    return ans;
}
int main()
{
    int W = 90, ans = 0;
    vector<int> wt = {20, 10, 50, 50};
    vector<int> val = {100, 60, 100, 200};
    ans = fracKnapsack(wt, val, W);

    cout << ans << endl;

    return 0;
}