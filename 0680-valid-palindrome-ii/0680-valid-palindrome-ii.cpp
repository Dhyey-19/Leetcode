class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end) {
            if(s[start] != s[end]) {
                return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
            }
            start++;
            end--;
        }    
        return true;
    }
};