class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine,  vector<bool>& isActive) {
        vector<pair<int, string>> valid;
        vector<string> categories = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i])
                continue;
            if (code[i].empty())
                continue;
            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode)
                continue;
            auto it = find(categories.begin(), categories.end(), businessLine[i]);
            if (it == categories.end())
                continue;
            int categoryIndex = it - categories.begin();
            valid.push_back({categoryIndex, code[i]});
        }
        sort(valid.begin(), valid.end());
        vector<string> result;
        for (auto& p : valid) {
            result.push_back(p.second);
        }
        return result;
    }
};