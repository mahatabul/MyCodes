#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    int n;
    cin>>n;


    vector<int>a(n),b(n),c(n);

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];

    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end());

    for (int i = 0; i < n; i++)
    {
        c[i]=(a[i]+b[i])%n;
    }
    
    
    for (int i = 0; i < n; i++)
    {
        cout<<c[i]<<" ";

    }

    return 0;
}