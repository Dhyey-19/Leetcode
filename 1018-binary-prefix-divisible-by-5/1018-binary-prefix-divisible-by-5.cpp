class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0; // Will store the value modulo 5
        
        for(int bit : nums) {
            x = (x * 2 + bit) % 5; // Update prefix modulo 5
            ans.push_back(x == 0); // Divisible by 5 if remainder is 0
        }
        
        return ans;
    }
};
