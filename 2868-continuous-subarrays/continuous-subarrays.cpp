#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxDq, minDq;
        ll count = 0;
        int left = 0;

        for(int right=0;right<nums.size(); right++) {
            while(!maxDq.empty() && nums[right] > maxDq.back()) {
                maxDq.pop_back();
            }
            maxDq.push_back(nums[right]);
            while(!minDq.empty() && nums[right] < minDq.back()) {
                minDq.pop_back();
            }
            minDq.push_back(nums[right]);

            while(!minDq.empty() && !maxDq.empty() && maxDq.front() - minDq.front() > 2) {
                if (nums[left] == maxDq.front()) maxDq.pop_front();
                if (nums[left] == minDq.front()) minDq.pop_front();
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};