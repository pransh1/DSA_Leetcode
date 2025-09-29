class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.assign(values.size(), vector<int>(values.size(), -1));
        return solve(values, 0, n-1);
    }

    int solve(vector<int>&nums, int i, int j) {
        if(j-i < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;

        for(int k=i+1; k<j; k++) {
            int prod = nums[i]*nums[j]*nums[k];
            int left = solve(nums, i, k);
            int right = solve(nums, k, j);
            int total = left + right + prod;
            mini = min(mini, total);
        }
        return dp[i][j] = mini;
    }
};