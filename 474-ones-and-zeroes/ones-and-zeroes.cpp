class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<pair<int, int>>& cnt, int i, int m, int n) {
        if(i == cnt.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int zeroes = cnt[i].first;
        int ones = cnt[i].second;
        // skip;
        int skip = 0;
        skip += 0 + solve(cnt, i+1, m, n);

        // take that string
        int take = 0;
        if(m >= zeroes && n >= ones) {
            take += 1 + solve(cnt, i+1, m - zeroes, n - ones);
        }

        return  dp[i][m][n] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<pair<int, int>> cnt;

        int zeroes = 0, ones = 0;

         for (string& s : strs) {
            int zeroes = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeroes++;
                else ones++;
            }
            cnt.push_back({zeroes, ones});
        }
        dp.assign(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(cnt, 0, m, n);
    }
};