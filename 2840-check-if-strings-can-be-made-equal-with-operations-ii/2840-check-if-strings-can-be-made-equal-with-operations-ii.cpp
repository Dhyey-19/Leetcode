class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even, odd;

        for(int i = 0; i < s1.length(); i++) {
            if(i % 2 == 0) {
                even[s1[i]]++;
            } else {
                odd[s1[i]]++;
            }
        }

        for(int i = 0; i < s2.length(); i++) {
            if(i % 2 == 0) {
                even[s2[i]]--;
            } else {
                odd[s2[i]]--;
            }
        }

        // check all values are zero
        for(auto &p : even) {
            if(p.second != 0) return false;
        }
        for(auto &p : odd) {
            if(p.second != 0) return false;
        }

        return true;
    }
};