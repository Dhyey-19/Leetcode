class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> r1={'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> r2={'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> r3={'z','x','c','v','b','n','m'};
        vector<string> res;

        for(string w : words) {
            string temp = w;
            for(char &ch : temp) {
                ch = tolower(ch);
            }

            auto& row = r1.count(temp[0]) ? r1 : (r2.count(temp[0]) ? r2 : r3);
            bool valid = true;
            for(char ch : temp) {
                if(!row.count(ch)) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                res.push_back(w);
            }
        }
        return res;
    }
};