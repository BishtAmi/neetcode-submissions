class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin(n), rightMin(n);
        stack<int> st, st1;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                leftMin[i] = -1;
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    leftMin[i] = -1;
                } else {
                    leftMin[i] = st.top();
                }
                st.push(i);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (st1.empty()) {
                rightMin[i] = n;
                st1.push(i);
            } else {
                while (!st1.empty() && heights[st1.top()] >= heights[i]) {
                    st1.pop();
                }
                if (st1.empty()) {
                    rightMin[i] = n;
                } else {
                    rightMin[i] = st1.top();
                }
                st1.push(i);
            }
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max(ans, heights[i] * (rightMin[i] - leftMin[i] - 1));
        }

        return ans;
    }
};
