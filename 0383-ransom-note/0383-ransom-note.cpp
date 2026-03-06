class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);
        for(char ch : magazine) {
            cnt[ch - 'a']++;
        }
        for(char ch : ransomNote) {
            if(--cnt[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};