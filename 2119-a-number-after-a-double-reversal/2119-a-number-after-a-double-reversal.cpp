class Solution {
public:
    bool isSameAfterReversals(int num) {
        // return true if (num is 0) or (last digit is not 0)
        return num % 10 || num == 0;
    }
};