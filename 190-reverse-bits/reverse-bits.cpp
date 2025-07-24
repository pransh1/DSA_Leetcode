class Solution {
public:
    void addBits(int num, vector<int>& bits) {
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            bits.push_back(bit);
        }
    }
    int reverseBits(int x) {
        vector<int> x_bit;

        addBits(x, x_bit);

        reverse(x_bit.begin(), x_bit.end());

        unsigned int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | x_bit[i];
        }
        return ans;
    }
};

