class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // if(n == 0) return;
        k = k % n;
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};