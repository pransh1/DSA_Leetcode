class Solution {
public:
    void addBits(int num, vector<int>& bits) {
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            bits.push_back(bit);
        }
    }
    int hammingDistance(int x, int y) {
        vector<int> x_bit;
        vector<int> y_bit;

        addBits(x, x_bit);
        addBits(y, y_bit);
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (x_bit[i] != y_bit[i]) {
                count++;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int ans = 0;
//         int val = x^y;
//         while(val != 0) {
//             ans += (val & 1);
//             val >>= 1;
//         }
//         return ans;
//     }
// };