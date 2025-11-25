class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        int longest = 0;
        for(auto &p : freq) {
            int x = p.first;
            if(freq.count(x + 1)) {
                longest = max(longest, freq[x] + freq[x + 1]);
            }
        }
        return longest;
    }
};
