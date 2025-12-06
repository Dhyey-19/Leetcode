class Solution {
public:
    string customSortString(string order, string s) {
        // Step 1: Count frequency of each char in s
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }

        string res = "";

        // Step 2: add chars in the order of "order"
        for(char ch : order) {
            if (freq.count(ch)) {
                res.append(freq[ch], ch);  // add 'ch' freq[ch] times
                freq.erase(ch);          // remove since fully used
            }
        }

        // Step 3: add remaining chars (not in order)
        for (auto &p : freq) {
            res.append(p.second, p.first);
        }

        return res;
    }
};
