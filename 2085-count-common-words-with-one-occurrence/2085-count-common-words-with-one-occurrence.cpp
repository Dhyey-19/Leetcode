class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for(string str : words1) {
            mp1[str]++;
        }    
        for(string str : words2) {
            mp2[str]++;
        }
        int cnt = 0;
        for(string s : words1) {
            if(mp1[s] == 1 && mp2[s] == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};