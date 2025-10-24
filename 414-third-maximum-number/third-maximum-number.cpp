class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        
        long largest = LONG_MIN;
        long secondLargest = LONG_MIN;
        long thirdLargest = LONG_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] == largest || nums[i] == secondLargest || nums[i] == thirdLargest) continue;
            if(nums[i] > largest) {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > secondLargest) {
                thirdLargest = secondLargest;
                secondLargest = nums[i];
            }
            else if(nums[i] > thirdLargest) {
                thirdLargest = nums[i];
            }
        } 
        return thirdLargest != LONG_MIN ? thirdLargest : largest;
    }
};