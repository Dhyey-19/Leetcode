class Solution {
public:
    bool isVowel(char ch) {
        char lwr = tolower(ch);
        return lwr == 'a' || lwr == 'e' ||lwr == 'i' || lwr == 'o' || lwr == 'u';   
    }

    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            if(isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left++], s[right--]);
            } else if(!isVowel(s[left])) {
                left++;
            } else if(!isVowel(s[right])){
                right--;
            }
        }
        return s;
    }
};