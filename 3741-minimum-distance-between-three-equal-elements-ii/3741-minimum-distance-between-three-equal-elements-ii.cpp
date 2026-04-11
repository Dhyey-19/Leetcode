class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int minDistance = INT_MAX;
        for(auto &m : mp) {
            vector<int> &v = m.second;
            if(v.size() < 3) {
                continue;
            }
            for(int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                minDistance = min(minDistance, dist);
            }
        }
        return minDistance == INT_MAX ? -1 : minDistance;
    }
};