#include<bits/stdc++.h>
class Solution {
   public:
    int dp[1001];
    int solve(int i, vector<int>& nums) {
        if (i >= nums.size() - 1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        for (int j = 1; j <= nums[i]; j++) {
            int cur = 1 + solve(i + j, nums);
            ans = min(ans,cur);
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};
