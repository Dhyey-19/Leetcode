class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        vector<int> lwr(26, -1);
        vector<int> upr(26, -1);
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(isupper(ch)) {
                // store first uppercase occurrence
                if(upr[ch - 'A'] == -1) {
                    upr[ch - 'A'] = i;
                }
            } else {
                // store last lowercase occurrence
                lwr[ch - 'a'] = i;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(lwr[i] != -1 && upr[i] != -1 && lwr[i] < upr[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};