class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for(int d : deck) {
            freq[d]++;
        }
        
        int g = 0;
        for(auto it : freq) {
            g = __gcd(g, it.second);
        }
        
        return g > 1;
    }
};