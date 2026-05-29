class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a' && i > 0) {
                if(s[i - 1] == 'b') {
                    return false;
                }
            }
        }      
        return true;
    }
};