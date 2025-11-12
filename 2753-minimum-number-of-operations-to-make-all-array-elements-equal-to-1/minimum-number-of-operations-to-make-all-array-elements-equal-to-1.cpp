class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int overallgcd = 0;
        for(int x : nums) {
            overallgcd = gcd(overallgcd, x);
        }
        if(overallgcd > 1) return -1;
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;
         int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        if (minLen == INT_MAX) return -1;
        return (minLen - 1) + (n - 1);
    }   
};