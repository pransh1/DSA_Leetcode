class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n+1);
        for(int num : nums) {
            if(num > 0 && num <= n) {
                vis[num] = true;
            }
        }

        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                return i;
            }
        }

        return n+1;
    }
};