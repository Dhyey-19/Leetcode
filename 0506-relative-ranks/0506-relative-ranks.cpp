class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        unordered_map<int,string> mp;

        vector<int> temp = score;
        sort(temp.begin(), temp.end(), greater<int>());

        for(int i = 0; i < temp.size(); i++) {

            if(i == 0)
                mp[temp[i]] = "Gold Medal";
            else if(i == 1)
                mp[temp[i]] = "Silver Medal";
            else if(i == 2)
                mp[temp[i]] = "Bronze Medal";
            else
                mp[temp[i]] = to_string(i + 1);
        }

        vector<string> res(score.size());

        for(int i = 0; i < score.size(); i++) {
            res[i] = mp[score[i]];
        }

        return res;
    }
};