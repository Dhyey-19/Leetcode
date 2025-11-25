class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
 
    string sortVowels(string s) {
        vector<char> vowels;
        for (char ch : s) {
            if(isVowel(ch)) {
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(), vowels.end());
        string t = s;
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                t[i] = vowels[idx++];
            }
        }
        return t;
    }
};