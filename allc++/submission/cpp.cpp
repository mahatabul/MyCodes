#include <bits/stdc++.h>
#include <string>
using namespace std;

bool comp(int &a, int &b)
{
    return (a >= b);
}
long long maxPoints(vector<int> &technique1, vector<int> &technique2, int k)
{
    long long ans = 0;
    int n = technique1.size();
    sort(technique1.begin(), technique1.end(), comp);
    sort(technique2.begin(), technique2.end(), comp);

    for (int i = 0; i < k; i++)
    {
        ans += technique1[i];
    }

    for (int i = 0; i < n - k; i++)
    {
        ans += max(technique1[k + i], technique2[i]);
    }

    return ans;
}
int main()
{
    vector<int> t = {10, 40, 20};
    maxPoints(t, t, 3);

    return 0;
}