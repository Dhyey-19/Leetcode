class Solution {
public:
    bool isHappy(int n) {
        int next = getDigitSum(n);
        while (next >= 10)
            next = getDigitSum(next);
        if (next == 1 || next == 7)
            return true;
        return false;
    }
    int getDigitSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};