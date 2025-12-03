class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int N = nums.size(); 
        long long res = LLONG_MAX, sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0LL);

        int n = N/2;
        vector<vector<long long>> left(n+1), right(n+1);

        // storing all possible subset sum in left and right
        // meet in the middle algorithm
        for(int mask = 0; mask<(1<<n); ++mask) {
            int sz = 0;
            long long l = 0, r = 0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        // sort right part as we will do binary search on right part
        for(int sz = 0; sz<=n; ++sz) {
            sort(right[sz].begin(), right[sz].end());
        }

        // iterating over left part
        for(int sz=0; sz<=n;++sz) {
            for(auto& a : left[sz]) {
                long long b = (sum - 2LL*a)/2LL;
                int rsz = n-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(), b); // binary search

                if(itr != v.end()) {
                    res = min(res, abs(sum - 2LL*(a+(*itr)))); // min(res, sum - 2*(a+b))
                }

                if(itr != v.begin()) {
                    auto it = itr; --it;
                    res = min(res, abs(sum - 2LL*(a+(*it))));
                }
            }
        }
        return (int)res;
    }
};