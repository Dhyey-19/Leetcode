class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, leave = 0;
        for(int i = 0; i < s.length(); i++) { 
            if(s[i] == 'P') {
                continue;
            } else if(s[i] == 'A') {
                absent++;
            } else if(s[i] == 'L') {
                if(i > 0 && s[i - 1] == 'L') {
                    leave++;
                } else {
                    leave = 1;
                }
            }
            if(absent >= 2) {
                return false;
            }
            if(leave >= 3) {
                return false;
            }
        }    
        return true;
    }
};