class Solution {
public:
    
    void dfs(TreeNode* root, unordered_map<int,int>& freq) {
        if(!root) return;

        freq[root->val]++;
        dfs(root->left, freq);
        dfs(root->right, freq);
    }

    vector<int> findMode(TreeNode* root) {

        unordered_map<int,int> freq;
        dfs(root, freq);
        int maxFreq = 0;
        for(auto &p : freq)
            maxFreq = max(maxFreq, p.second);

        vector<int> res;
        for(auto &p : freq)
            if(p.second == maxFreq)
                res.push_back(p.first);

        return res;
    }
};