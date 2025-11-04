class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int i = 0;
        int j = 0; 
        unordered_map<int, int> mp;
        vector<int> ans;
          
        // sliding window 
        // logic is to run sliding window till j < k-1 and then store freq and then calculate sum of those 
        // whose freq is more than x and if freq == x then take the high elem and add it in Xsum;
        // at the end return the final arr;

        while(j<n) {
            mp[nums[j]]++;

            if(j-i+1 < k) {
                j++;
                continue;
            }

            if(j-i+1 == k) {
                vector<pair<int, int>> freq(mp.begin(), mp.end());

                sort(freq.begin(), freq.end(), [&](auto &a, auto &b) {
                    if(a.second == b.second) {
                        return a.first > b.first;
                    }
                    return a.second > b.second;
                });

                int Xsum = 0;
                int taken = 0;

                for(auto &p : freq) {
                    if(taken == x) break;
                    Xsum += p.first * p.second;
                    taken++;
                }
                ans.push_back(Xsum);

                mp[nums[i]]--;

                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};