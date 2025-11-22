#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fastio;

    int n;
    cin>>n;

    string s;
    cin>>s;

    for (int i = 0; i < n-1; i++)
    {
        if ((s[i]=='a' and s[i+1]=='b') or (s[i]=='b' and s[i+1]=='a'))
        {
            cout<<"Yes";
            return 0;
        }
        
    }
    
    cout<<"No";

    return 0;
}