class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ops = 0;
        int n = nums.size();

        for(int i = n-2; i >= 0; i--) {
            if(nums[i] <= nums[i+1]) continue;
            int parts = nums[i]/nums[i+1];
            if(nums[i] % nums[i+1] != 0) parts++;

            ops += parts - 1;
            nums[i] = nums[i]/parts;
        }
        return ops;
    }
};