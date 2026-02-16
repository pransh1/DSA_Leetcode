class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int max_len = 0;

        for(int i=0;i<n;i++) {
            set<int> odd_st;
            set<int> even_st;
            for(int j=i;j<n;j++) {
                if(nums[j] % 2 == 0) {
                    even_st.insert(nums[j]);
                }
                else {
                    odd_st.insert(nums[j]);
                }

                if (odd_st.size() == even_st.size()) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
        
    }
};