class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size() + 1, 0);
        vector<int> res(A.size(), 0);
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2)
                cnt++;

            freq[B[i]]++;
            if (freq[B[i]] == 2)
                cnt++;

            res[i] = cnt;
        }
        return res;
    }
};