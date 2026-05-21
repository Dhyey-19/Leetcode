class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;
        int cnt = 0;
        for (int a : arr1) {
            string str = to_string(a);
            string prefix = "";
            for (char ch : str) {
                prefix += ch;
                s.insert(prefix);
            }
        }
        for (int a : arr2) {
            string str = to_string(a);
            string prefix = "";
            for(int i = 0; i < str.length(); i++) {
                prefix += str[i];
                if(s.count(prefix)) {
                    cnt = max(cnt, i + 1);
                }
            }
        }
        return cnt;
    }
};
