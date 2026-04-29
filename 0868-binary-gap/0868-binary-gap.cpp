class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;   // stores previous position of 1
        int ans = 0;
        int pos = 0;

        while(n > 0) {
            if(n & 1) {   // current bit is 1
                if(prev != -1) {
                    ans = max(ans, pos - prev);
                }
                prev = pos;
            }
            n >>= 1;   // move to next bit
            pos++;
        }

        return ans;
    }
};