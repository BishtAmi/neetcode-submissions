#include<bits/stdc++.h>
class Solution {
   public:
    int n;
    int dp[5001][2];
    int solve(int i, int type, vector<int>& prices) {
        if (i >= n) {
            return 0;
        }
        if(dp[i][type] != -1) return dp[i][type];
        int buy = 0, sell = 0, skip = solve(i + 1, type, prices);
        if (type == 0) {
            buy = -prices[i] + solve(i + 1, 1, prices);
        } else
            sell = prices[i] + solve(i + 2, 0, prices);

        return dp[i][type] = max(skip,max(buy, sell));
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, prices);
    }
};
