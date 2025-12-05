// class Solution {
// public:
//     // find first index of target
//     int firstPos(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1, ans = -1;
//         while(l <= r) {
//             int mid = l + (r - l) / 2;
//             if(nums[mid] >= target) {            // go left if found or bigger
//                 if(nums[mid] == target) ans = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }

//     // find last index of target
//     int lastPos(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1, ans = -1;
//         while(l <= r) {
//             int mid = l + (r - l) / 2;
//             if(nums[mid] <= target) {            // go right if found or smaller
//                 if(nums[mid] == target) ans = mid;
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return ans;
//     }

//     vector<int> targetIndices(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());         

//         int start = firstPos(nums, target);     
//         int end = lastPos(nums, target);       

//         vector<int> ans;
//         if(start == -1) return ans;             

//         for(int i = start; i <= end; i++)
//             ans.push_back(i);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> indices;
        for(int i = 0;i<nums.size();i++)
            if(nums[i] == target) indices.push_back(i);
        return indices;
    }
};