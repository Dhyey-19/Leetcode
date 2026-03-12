class Solution {
public: 
    TreeNode* prev = nullptr;  
    int count = 0;
    int maxCount = 0;
    vector<int> result; 

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        if (prev == nullptr) { 
            count = 1; 
        } 
        else if (prev->val == root->val) { 
            count++; 
        } 
        else { 
            count = 1; 
        } 

        if (count > maxCount) { 
            maxCount = count; 
            result.clear(); 
            result.push_back(root->val); 
        } 
        else if (count == maxCount) { 
            result.push_back(root->val); 
        } 

        prev = root;  // Update prev to current node

        inorder(root->right);
    } 

    vector<int> findMode(TreeNode* root) { 
        inorder(root); 
        return result; 
    } 
};