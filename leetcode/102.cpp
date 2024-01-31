/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    inline vector<vector<int>> levelOrder(
        const TreeNode * const root
    ) const noexcept {
        vector<vector<int>> result{};
        queue<pair<const TreeNode *, size_t>> q{};
        if (root)
            q.emplace(root, 0);
        while (!q.empty()) {
            const auto [treeNode, level]{q.front()};
            q.pop();
            if (result.size() <= level)
                result.emplace_back();
            result.back().push_back(treeNode->val);
            if (treeNode->left)
                q.emplace(treeNode->left, level + 1);
            if (treeNode->right)
                q.emplace(treeNode->right, level + 1);
        }
        return result;
    }
};
