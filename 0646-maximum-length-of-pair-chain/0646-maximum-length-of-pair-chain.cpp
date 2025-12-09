class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];  // sort by ending time
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);

        int cnt = 1;
        int lastEnd = pairs[0][1];

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > lastEnd) { // valid chain condition
                cnt++;
                lastEnd = pairs[i][1];
            }
        }
        return cnt;
    }
};
