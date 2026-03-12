class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(char& ch : word) {
            if(isupper(ch)) {
                cap++;
            }
        }
        return cap == word.size() || cap == 0 || (cap == 1 && isupper(word[0])); 
    }
};