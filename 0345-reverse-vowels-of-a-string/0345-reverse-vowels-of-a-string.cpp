class Solution {
public:
    bool isVowel(char ch) {
        char lwr = tolower(ch);
        return lwr == 'a' || lwr == 'e' ||lwr == 'i' || lwr == 'o' || lwr == 'u';   
    }

    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            while(!isVowel(s[left]) && left < right) {
                left++;
            }
            while(!isVowel(s[right]) && left < right) {
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};