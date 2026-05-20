class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openstk, starstk;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '(') {
                openstk.push(i);
            } else if(ch == '*') {
                starstk.push(i);
            } else { // ')'
                if(!openstk.empty()) {
                    openstk.pop();
                } else if(!starstk.empty()) {
                    starstk.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*'
        while(!openstk.empty() && !starstk.empty()) {
            if(openstk.top() < starstk.top()) {
                openstk.pop();
                starstk.pop();
            } else {
                return false;
            }
        }
        return openstk.empty();
    }
};