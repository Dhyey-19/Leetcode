class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int cnt = 0;
        for(char ch : s) {
            int idxInS = s.find(ch);
            int idxInT = t.find(ch);
            cnt += abs(idxInS - idxInT);
        }
        return cnt;
    }
};