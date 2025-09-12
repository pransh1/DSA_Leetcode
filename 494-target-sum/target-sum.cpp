class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        return calculateWays(nums, 0, sum, target);
    }
    int calculateWays(vector<int>& nums, int currIdx, int currSum, int target) {
        int totalWays = 0;
        if(currIdx == nums.size()) {
            if(currSum == target) {
                return 1;  
            } 
            else {
                return 0;
            }
        }
        totalWays += calculateWays(nums, currIdx+1, currSum + nums[currIdx], target);
        totalWays += calculateWays(nums, currIdx+1, currSum - nums[currIdx], target);
        return totalWays;
    }
};