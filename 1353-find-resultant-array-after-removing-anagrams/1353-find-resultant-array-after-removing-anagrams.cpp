class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        for(string& word : words) {
            if(!res.empty()) {
                string prev = res.back();
                string curr = word;
                sort(prev.begin(), prev.end());
                sort(curr.begin(), curr.end());
                if(prev == curr) {
                    continue;
                }
            }
            res.push_back(word);
        }    
        return res;
    }
};