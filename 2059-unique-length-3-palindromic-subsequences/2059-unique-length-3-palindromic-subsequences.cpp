class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;

        // Store first and last occurrence of each character
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int first = -1, last = -1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ch) {
                    if (first == -1) {
                        first = i;
                    }
                    last = i;
                }
            }
            if(first == -1 || first == last) {
                continue;
            }
            unordered_set<char> middle;
            for(int i = first + 1; i < last; i++) {
                middle.insert(s[i]);
            }
            cnt += middle.size();
        }
        return cnt;
    }
};