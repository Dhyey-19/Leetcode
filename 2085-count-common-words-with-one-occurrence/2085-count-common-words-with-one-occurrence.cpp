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
        for(auto &[str, f] : mp1) {
            if(f == 1 && mp2[str] == 1) {
                cnt++;
            } 
        }
        return cnt;
    }
};