class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int totalNeed = 1 << k;
        if (n - k + 1 < totalNeed) return false;
        vector<bool> seen(totalNeed, false);
        int hash = 0;
        for (int i = 0; i < n; ++i) {
            hash = ((hash << 1) & (totalNeed - 1)) | (s[i] - '0');
            if (i >= k - 1) {
                seen[hash] = true;
            }
        }
        for (bool val : seen) {
            if (!val) return false;
        }
        return true;
    }
};