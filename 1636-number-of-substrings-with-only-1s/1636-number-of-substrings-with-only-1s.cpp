class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long len = 0;
        long long cnt = 0;
        for(char ch : s) {
            if(ch == '1') {
                len++;
            } else {
                cnt = (cnt + (len * (len + 1) / 2) % MOD) % MOD;
                len = 0;
            }
        }
        cnt = (cnt + (len * (len + 1) / 2) % MOD) % MOD;
        return cnt;
    }
};