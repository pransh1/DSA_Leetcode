class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long first = LONG_MAX, second = LONG_MAX;

        for(int num : nums) {
            if(num <= first) first = num;          // smallest
            else if(num <= second) second = num;   // second smallest
            else return true;                      // found triplet
        }
        return false;
    }
};
