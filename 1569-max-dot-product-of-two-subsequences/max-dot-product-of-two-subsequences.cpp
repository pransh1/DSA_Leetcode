class Solution {
public:
    int n, m;
    vector<vector<int>> memo;
    const int NEG_INF = -1e9;

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        // If one array is exhausted, no valid subsequence possible
        if (i == n || j == m) {
            return NEG_INF;
        }

        if (memo[i][j] != INT_MIN) {
            return memo[i][j];
        }

        // Option 1: take both elements
        int take = nums1[i] * nums2[j];
        int next = solve(i + 1, j + 1, nums1, nums2);
        if (next > 0) {
            take += next;
        }

        // Option 2: skip element from nums1
        int skip1 = solve(i + 1, j, nums1, nums2);

        // Option 3: skip element from nums2
        int skip2 = solve(i, j + 1, nums1, nums2);

        return memo[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& A, vector<int>& B) {
        n = A.size();
        m = B.size();
        // memo.assign(n, vector<int>(m, INT_MIN));

        // return solve(0, 0, nums1, nums2);

        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = A[i] * B[j];
                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
