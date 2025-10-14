

class Solution {
public:
    // vector<vector<int>> subs;
    // void subArr(vector<int>& nums, int start, int end) {
    //     if(end == nums.size()) return;

    //     if(start > end) {
    //         subArr(nums, start, end+1);
    //         return;
    //     }

    //     vector<int> sub(nums.begin() + start, nums.begin() + end + 1);
    //     subs.push_back(sub);

    //     subArr(nums, start+1, end);
    // }



    bool isIncrease(vector<int>& nums, int start, int k) {
        if (start + k - 1 >= nums.size()) return false;
        for(int i=start + 1; i < start + k; i++) {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
         if (n < 2 * k) return false;
        for(int i=0; i<nums.size(); i++) {
            
            if(isIncrease(nums, i, k) && isIncrease(nums, i+k, k)) {
                return true;
            }
        }
        return false;
    }
};