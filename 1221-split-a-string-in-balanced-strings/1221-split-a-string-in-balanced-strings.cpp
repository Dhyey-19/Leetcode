class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0, cnt = 0;
        for(char ch : s) {
            if(ch == 'L') {
                cnt++;
            } else {
                cnt--;
            }
            if(cnt == 0) {
                res++;
            }
        }    
        return res;
    }
};