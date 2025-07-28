class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> unique_non_zero;
        for (int x : nums) {
            if (x != 0) {
                unique_non_zero.insert(x);
            }
        }
        return unique_non_zero.size();
    }
};
