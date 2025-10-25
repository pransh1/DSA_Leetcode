class Solution {
public:
    int subtractProductAndSum(int n) {
        int copy1 = n;
        int copy2 = n;
        int prod = 1;
        int sum = 0; 

        // prod
        while(copy1>0) {
            int pop = copy1 % 10;
            prod *= pop;
            copy1/= 10;
        }

        // sum
        while(copy2 > 0) {
            int pop = copy2 % 10;
            sum += pop;
            copy2 /= 10;
        }

        // their diff
        return prod - sum;
    }
};