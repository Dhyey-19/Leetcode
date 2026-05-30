class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == ch) {
                int start = 0;
                int end = i;
                while(start < end) {
                    swap(word[start], word[end]);
                    start++;
                    end--;
                }
                return word;
            }
        }
        return word;
    }
};