class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int i : nums) {
            mp[i]++;
        }
        int sum = 0;
        for (auto& [num, count] : mp) {
            if (count % k == 0) {
                sum += num * count;
            }
        }

        return sum;
    }
};