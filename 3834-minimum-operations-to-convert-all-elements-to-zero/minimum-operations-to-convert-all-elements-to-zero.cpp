class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        stack<int> monotonic;

        // create increasing monotonic stack and push till values are in descending order
        for(int i=0;i<n;i++) {
            // if nums[i] == 0 simply remove it from stack
            if(nums[i] == 0) {
                while(!monotonic.empty()){
                    monotonic.pop();
                }
                continue;
            }
            // if its not in order increasing order pop the top val of stack until it is back
            // in its increasing order
            while(!monotonic.empty() && nums[monotonic.top()] > nums[i]) {
                monotonic.pop();
            }

            if(monotonic.empty() || nums[monotonic.top()] < nums[i]) {
                monotonic.push(i);
                ops++;
            }
        }
        return ops;
    }
};