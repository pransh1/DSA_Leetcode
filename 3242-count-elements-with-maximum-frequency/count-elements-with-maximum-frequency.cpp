class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        int count = 0;
        int maxFreq = INT_MIN;
        for(unordered_map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if((*it).second > maxFreq) {
                maxFreq = (*it).second;
            }
        }

        for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if((*it).second == maxFreq) {
                count += maxFreq;
            }
        }

        return count;
    }
};