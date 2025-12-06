#include<bits/stdc++.h>
using namespace std;
// memoization (top-down)
/* 
int maxprice(vector<int>price,int n,vector<int>&dp){

    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    int maxVal = 0;
    for(int i=1;i<=n;i++){
        maxVal = max(maxVal,price[i-1]+maxprice(price,n-i,dp));
    }

    return dp[n]=maxVal;
}

int rodcutting(vector<int>price,int n){
    vector<int>dp(n+1,-1);
    return maxprice(price,n,dp);
}
 */

// tabulation (bottom-up)
int rodcutting(vector<int>price,int n){
    vector<int>dp(n+1,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = max( dp[i] , price[j-1] + dp[i-j]);
        }
    }
    return dp[n];
}

int main(){
    
    vector<int> price = {2, 5, 7, 8};
    int n = 4;
    cout << "Rod length: " << n << endl;
    cout << "Maximum profit: " << rodcutting(price, n) << endl;
}