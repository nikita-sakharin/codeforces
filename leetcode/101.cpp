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
class Solution final {
public:
    inline bool isSymmetric(const TreeNode * const root) const noexcept {
        stack<pair<TreeNode *, TreeNode *>> s{};
        s.emplace(root->left, root->right);
        do {
            const auto [left, right] = s.top();
            s.pop();
            if (bool(left) != bool(right))
                return false;
            if (left) {
                if (left->val != right->val)
                    return false;
                s.emplace(left->left, right->right);
                s.emplace(left->right, right->left);
            }
        } while (!s.empty());
        return true;
    }
};
