class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(128, 0);
        for(char ch : s) {
            cnt[ch]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });
        return s;
    }
};