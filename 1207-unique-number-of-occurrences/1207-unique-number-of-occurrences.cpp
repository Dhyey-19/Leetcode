class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int a : arr) {
            freq[a]++;
        }
        unordered_set<int> s;
        for(auto f : freq) {
            s.insert(f.second);
        }
        return freq.size() == s.size();
    }
};