class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n+1, -1));
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int idx, int prev) {
        // idx ---> current element
        // current element ---> LIS
        // current  <= prev  ----> current skip
        // current > prev ---> current ho sakta hai
        if(idx >= nums.size()) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int take = 0;
        int skip = 0;
        
        if(prev == -1 || nums[idx] > nums[prev]) {
            //take
            take = 1 + solve(nums, idx+1, idx);
            // skip
            skip = 0 + solve(nums, idx+1, prev);
        }
        else if(nums[idx] <= nums[prev]) {
            skip = 0 + solve(nums, idx+1, prev);
        }

        return dp[idx][prev+1] = max(take, skip);
    }
};