class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i=0;

        // strictly increasing
        while(i+1 < n && nums[i] < nums[i+1]) {
            i++;
        }
        if(i==0) return false;
        int p=i;

        // strictly decreasing
        while(i+1<n && nums[i] > nums[i+1]) {
            i++;
        }
        if(i==p) return false;
        int q = i;

        // strictly increasing
        while(i+1<n && nums[i] < nums[i+1]) i++;

        if(i==q) return false;

        return i == n-1;
    }
};