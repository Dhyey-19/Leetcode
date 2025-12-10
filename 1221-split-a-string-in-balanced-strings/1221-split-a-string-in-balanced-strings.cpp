class Solution {
public:
    int balancedStringSplit(string s) {
        int rcnt = 0, lcnt = 0, cnt = 0;
        for(char ch : s) {
            if(ch == 'L') {
                lcnt++;
            } else {
                rcnt++;
            }
            if(lcnt == rcnt) {
                cnt++;
                lcnt = 0;
                rcnt = 0;
            }
        }    
        return cnt;
    }
};