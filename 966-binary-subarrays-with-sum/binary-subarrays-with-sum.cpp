class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return slidingWindowToFindTotalSubArr(nums, goal) - slidingWindowToFindTotalSubArr(nums, goal - 1);
    }

    int slidingWindowToFindTotalSubArr(vector<int>& nums, int goal) {
        int l = 0;
        int currSum = 0;
        int totalSubArr = 0;
        for(int r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while(l <= r && currSum > goal) {
                currSum -= nums[l++];
            }
            totalSubArr += r - l + 1;
        }
        return totalSubArr;
    }
};