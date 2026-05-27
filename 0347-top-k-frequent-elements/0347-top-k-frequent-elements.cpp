// USING PQ
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        priority_queue<pair<int, int>> pq;
        for (auto ent : mp)
            pq.push({ent.second, ent.first});
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};

// USING BUCKET SORT

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         for(int num : nums) {
//             mp[num]++;
//         }
//         vector<vector<int>> bucket(nums.size() + 1);
//         for(auto it : mp) {
//             int num = it.first;
//             int freq = it.second;
//             bucket[freq].push_back(num);
//         }
//         vector<int> ans;
//         for(int i = bucket.size() - 1; i >= 0; i--) {
//             for(int num : bucket[i]) {
//                 ans.push_back(num);
//                 if(ans.size() == k) {
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };