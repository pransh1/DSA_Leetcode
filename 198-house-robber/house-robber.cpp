class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return solve(nums, 0);
    }
    int solve(vector<int>&nums, int i) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        // i won't steal
        int skip = 0 + solve(nums, i+1);

        // if i am stealing
        int steal = nums[i] + solve(nums, i+2);
        return dp[i] = max(skip, steal);
    }
};