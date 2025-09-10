class Solution {
public:
    int recursion(int i, int j, vector<vector<int>>& dp) {
        if(i<0 || j<0 ) return 0;
        if(i==0 && j==0) return 1;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = recursion(i-1, j, dp)+recursion(i, j-1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return recursion(m-1, n-1, dp);
    }
};