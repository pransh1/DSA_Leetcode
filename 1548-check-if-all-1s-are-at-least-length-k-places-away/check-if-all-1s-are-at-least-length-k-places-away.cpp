class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ones;

        // collect all positions of 1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ones.push_back(i);
            }
        }
        for (int i = 1; i < ones.size(); i++) {
            if (ones[i] - ones[i-1] - 1 < k) {
                return false;
            }
        }

        return true; 
    }
};
