class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int cnta = __builtin_popcount(a);
            int cntb = __builtin_popcount(b);
            return cnta != cntb ? cnta < cntb : a < b;
        });
        return arr;
    }
};