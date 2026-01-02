class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        // store each elements count
        unordered_map<int, int> mp;
        for(auto& a : nums) {
            mp[a]++;
        }

        //now compare count of elem == n
        for(auto& num : mp) {
            if(num.second >= n/2) {
                return num.first;
            }
        }
        return -1;
    }
};