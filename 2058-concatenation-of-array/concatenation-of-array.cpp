class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>fullNums(2*n);
        
        for(int i=0;i<n;i++) {
            fullNums[i] = nums[i];
        }

        for(int i=0;i<n;i++) {
            fullNums[i+n] = nums[i];
        }

        return fullNums;
    }
};