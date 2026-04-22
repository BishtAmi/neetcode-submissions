class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }

        for (int i = 2; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + i < n and s[j] == s[j + i] and dp[j + 1][j + i - 1]) {
                    dp[j][j+i] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                //cout << i << " " << j << " " << dp[i][j] << "\n";
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};
/*
  aaaaa

  a, aa, aaa, aaaa, aaaaa
  a, aa, aaa, aaaa
  a, aa, aaa
  a, aa
  a

*/
