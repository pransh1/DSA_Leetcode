// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
        
//     }
// };

class Solution {
public:
    void addBits(int num, vector<int>& bits) {
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            bits.push_back(bit);
        }
    }
    int minBitFlips(int x, int y) {
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

