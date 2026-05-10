class Solution {
   public:
    bool isMatch(string t, map<int, int>& freq) {
        for (auto ch : t) {
            if (freq[ch] < 0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        map<int, int> freq;
        for (auto ch : t) {
            freq[ch] -= 1;
        }
        int high = n, low = -1;
        for (int r = 0, l = 0; r < n; r++) {
            freq[s[r]] += 1;
            while (l <= r && isMatch(t, freq)) {
                if (high - low + 1 > r - l + 1) {
                    low = l;
                    high = r;
                }
                freq[s[l]] -= 1;
                l++;
            }
        }
        return low == -1 ? "" : s.substr(low, high - low + 1);
    }
};
