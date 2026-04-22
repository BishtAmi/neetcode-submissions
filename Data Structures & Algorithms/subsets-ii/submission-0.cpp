class Solution {
public:
    set<vector<int>> st;
    int n;
    void solve(int i,vector<int> temp,vector<int> &nums)
    {
        if(i == n)
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,temp,nums);
        temp.pop_back();
        solve(i+1,temp,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        solve(0,{},nums);
        vector<vector<int>> ans;
        for(auto vec:st)
        {
            ans.push_back(vec);
        }
        return ans;
    }
};
