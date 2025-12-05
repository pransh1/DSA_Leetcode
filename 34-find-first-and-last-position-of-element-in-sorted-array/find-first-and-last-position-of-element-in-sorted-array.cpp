class Solution {
public:

    int bs(vector<int>& nums, int l, int r, int target, bool first_found) {
        int n = nums.size();
        int ans = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                ans = mid;
                if(first_found) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);
        int first = bs(nums, 0, n-1, target, true);
        int last = bs(nums, 0, n-1, target, false);
        ans[0] = first;
        ans[1] = last;
        return ans; 
    }
};