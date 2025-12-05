class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int minIdx = 0, maxIdx = 0;
        
        // find index of min and max
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[minIdx]) minIdx = i;
            if(nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // ensure minIdx is smaller for easy calc
        if(minIdx > maxIdx) swap(minIdx, maxIdx);

        int removeFront = maxIdx + 1;
        int removeEnd = (n - minIdx);
        int removeBoth = (minIdx + 1) + (n - maxIdx);

        return min({removeFront, removeEnd, removeBoth});
    }
};
