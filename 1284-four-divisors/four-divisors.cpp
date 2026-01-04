// class Solution {
// public:

//     int divisor_count(int n) {
//         int count = 0;
//         for(int i=1;i*i<=n;i++) {
//             if(n%i==0) {
//                 if(i*i==n) {
//                     count+=1;
//                 }
//                 else {
//                     count +=2;
//                 }
//             }
//         }
//         return count;
//     }

//     vector<int> divisor_pair_vec(int n, vector<int>& pair) {
//         pair.clear();
//         for(int i=1; i*i<=n;i++) {
//             if(n%i == 0) {
//                 pair.push_back(i);

//                 if(i*i != n) {
//                     pair.push_back(n/i);
//                 }
//             }
//         }
//         return pair;
//     }

//     int sumFourDivisors(vector<int>& nums) {
//         int sum_of_divisor = 0;
//         vector<int> divisors;

//         for(int i=0;i<nums.size(); i++) {
//             if(divisor_count(nums[i]) == 4) {
//                 divisor_pair_vec(nums[i], divisors);
//                 for(int d: divisors) {
//                     sum_of_divisor += d;
//                 }
//             }
//         }

//         return sum_of_divisor;
//     }
// };

static const int MX = 100001;

int divisor_sum[MX];
int divisor_num[MX];

int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) { 
            divisor_num[j]++; 
            divisor_sum[j]+=i;
        }
    }
    return 0;
}();

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
    
        int ans = 0;
        for(int d : nums) {
            if(divisor_num[d] == 4) {
                ans += divisor_sum[d];
            }
        }

        return ans;

    }

};

