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
private:
    template<class T>
    using Stack = stack<T, vector<T>>;

public:
    inline bool isSameTree(
        const TreeNode * const first,
        const TreeNode * const second
    ) const noexcept {
        stack<pair<const TreeNode *, const TreeNode *>> s{};
        s.emplace(first, second);
        do {
            const auto [left, right]{s.top()};
            s.pop();
            if (bool(left) != bool(right))
                return false;
            if (left) {
                if (left->val != right->val)
                    return false;
                s.emplace(left->left, right->left);
                s.emplace(left->right, right->right);
            }
        } while (!s.empty());

        return true;
    }
};
