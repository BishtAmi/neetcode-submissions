class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0 , r = heights.size() - 1;
        int ans = 0;
        while(l <= r)
        {
            // cout<<l<<" "<<r<<" "<<(r - l) * min(heights[r],heights[l])<<'\n';
            ans = max(ans, (r - l) * min(heights[r],heights[l]));
            if(heights[l] < heights[r])
            {
                l++;
            }
            else r--;
        }
        return ans;
    }
};
