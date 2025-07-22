class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int l = 0;
        int r = 0;
        int sum = 0;
        int maxSum = 0;
        while(r<n) {
            while(st.count(nums[r])) {
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            st.insert(nums[r]);
            sum += nums[r];
            maxSum = max(maxSum, sum);
            r++;
        }
        return maxSum;
    }
};