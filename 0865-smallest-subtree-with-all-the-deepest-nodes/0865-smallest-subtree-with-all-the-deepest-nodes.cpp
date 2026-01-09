// class Solution {
// public:
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         if (!root) return nullptr;

//         unordered_map<TreeNode*, TreeNode*> parent;
//         queue<TreeNode*> q;
//         q.push(root);
//         parent[root] = nullptr;

//         vector<TreeNode*> lastLevel;

//         // BFS traversal
//         while (!q.empty()) {
//             int size = q.size();
//             lastLevel.clear();

//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 lastLevel.push_back(node);

//                 if (node->left) {
//                     parent[node->left] = node;
//                     q.push(node->left);
//                 }
//                 if (node->right) {
//                     parent[node->right] = node;
//                     q.push(node->right);
//                 }
//             }
//         }

//         unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());

//         // Move upward until one node remains
//         while (deepest.size() > 1) {
//             unordered_set<TreeNode*> next;
//             for (auto node : deepest) {
//                 next.insert(parent[node]);
//             }
//             deepest = next;
//         }

//         return *deepest.begin();
//     }
// };


// Optimal 

class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        
        pair<int, TreeNode*> left = dfs(node->left);
        pair<int, TreeNode*> right = dfs(node->right);
        
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        } else if (right.first > left.first) {
            return {right.first + 1, right.second};
        } else {
            return {left.first + 1, node};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};