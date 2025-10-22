class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        int rev = 0;

        while(num != 0) {
            int pop = num % 10;
            num /= 10;

            if(rev > INT_MAX/10 || rev < INT_MIN/10) return false;

            rev = (rev*10) + pop;
        } 

        return rev == x ? true : false;
    }
};