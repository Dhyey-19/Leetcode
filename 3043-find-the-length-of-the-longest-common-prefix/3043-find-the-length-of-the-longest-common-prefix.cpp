class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int x : arr1) {
            int t = x;
            vector<int> prefixes;
            while (t > 0) {
                prefixes.push_back(t);
                t /= 10;
            }
            reverse(prefixes.begin(), prefixes.end());
            for (int p : prefixes) {
                s.insert(p);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            int t = x;
            vector<int> prefixes;
            while (t > 0) {
                prefixes.push_back(t);
                t /= 10;
            }
            reverse(prefixes.begin(), prefixes.end());
            for (int p : prefixes) {
                if (s.count(p)) {
                    ans = max(ans, (int)to_string(p).length());
                }
            }
        }
        return ans;
    }
};