class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++) {
            if(nums[i] >= target){
                count++;
            }
        }
        return count;
    }
};