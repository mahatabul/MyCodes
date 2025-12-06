#include "bits/stdc++.h"
using namespace std;

vector<int>dp(100000,-1);

int rec(int n, vector<int> &cost)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -100000000;

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, cost[i] + rec(n - i, cost));
    }
    return dp[n] = ans;
}

void solve()
{
    int n;
    cout<<"Enter the total cost option number:";
    cin >> n; 

    cout<<"Enter the length of the rod you need to sell: ";
    int x;
    cin>>x; // rod size
    
    vector<int> cost(n + 1); 
    cost[0]=0;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];  // cost for each length

    int ans = rec(x, cost);
    cout << ans << endl;


}

int main()
{
    solve();
    return 0;
}