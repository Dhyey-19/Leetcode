class Solution {
public:
    string largestOddNumber(string num) {
        int idx = -1;
        string res = "";
        for(int i = num.size() - 1; i>= 0; i--) {
            int digit = num[i] - '0';
            if(digit % 2 == 1) {
                idx = i;
                break;
            }
        }
        for(int i = 0; i <= idx; i++) {
            res += num[i];
        }
        return res;
    }
};