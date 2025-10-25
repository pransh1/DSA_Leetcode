class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for(int i=0; i<n; i++) {
            // if not divisible by 3 we have to make it by doing ops
            // we can either subtract 1 or add by 1 the value for that index
            if(nums[i] % 3 != 0) {
                ops++;
            }
            // if all val from the array is divisible by 3 just continue and at the return 0
        }
        return ops;
    }
};