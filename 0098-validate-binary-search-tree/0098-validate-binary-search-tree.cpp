class Solution {
public:
    bool validate(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;

        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;

        return validate(root->left, min, root) &&
               validate(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};
