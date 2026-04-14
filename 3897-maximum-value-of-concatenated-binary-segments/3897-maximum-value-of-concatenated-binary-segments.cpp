class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<int> idx(n);

        for (int i = 0; i < n; i++) idx[i] = i;

        // 🔥 Optimized comparator (no strings)
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            int a1 = nums1[a], a0 = nums0[a];
            int b1 = nums1[b], b0 = nums0[b];

            int i = 0, j = 0;
            int lenA = a1 + a0, lenB = b1 + b0;
            int total = lenA + lenB;

            while (i < total && j < total) {
                int bitA, cntA;
                if (i < lenA) {
                    if (i < a1) { bitA = 1; cntA = a1 - i; }
                    else { bitA = 0; cntA = lenA - i; }
                } else {
                    int k = i - lenA;
                    if (k < b1) { bitA = 1; cntA = b1 - k; }
                    else { bitA = 0; cntA = lenB - k; }
                }

                int bitB, cntB;
                if (j < lenB) {
                    if (j < b1) { bitB = 1; cntB = b1 - j; }
                    else { bitB = 0; cntB = lenB - j; }
                } else {
                    int k = j - lenB;
                    if (k < a1) { bitB = 1; cntB = a1 - k; }
                    else { bitB = 0; cntB = lenA - k; }
                }

                if (bitA != bitB) return bitA > bitB;

                int step = min(cntA, cntB);
                i += step;
                j += step;
            }

            return false;
        });

        long long result = 0;

        // 🔥 Build final number
        for (int i : idx) {
            int ones = nums1[i];
            int zeros = nums0[i];

            // add ones
            for (int k = 0; k < ones; k++) {
                result = (result * 2 + 1) % MOD;
            }

            // add zeros
            for (int k = 0; k < zeros; k++) {
                result = (result * 2) % MOD;
            }
        }

        return result;
    }
};