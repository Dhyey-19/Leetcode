class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for(char ch : t)
            freq[ch - 'a']++;

        for(char ch : s)
            freq[ch - 'a']--;

        int ans = 0;

        for(int x : freq)
            ans += max(0, x);

        return ans;
    }
};