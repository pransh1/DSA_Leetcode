class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        while(nums.size() != 1) {
            vector<int> newNum;
            for(int i=1;i<nums.size();i++) {
                int val = (nums[i] + nums[i-1]) % 10;
                newNum.push_back(val);
            }
            nums = newNum;

        }
        
        return nums[0];
    }
};