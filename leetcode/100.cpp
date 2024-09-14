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
        Stack<pair<const TreeNode *, const TreeNode *>> lifo{};
        lifo.emplace(first, second);
        do {
            const auto [left, right]{lifo.top()};
            lifo.pop();
            if (bool(left) != bool(right))
                return false;
            if (left) {
                if (left->val != right->val)
                    return false;
                lifo.emplace(left->left, right->left);
                lifo.emplace(left->right, right->right);
            }
        } while (!empty(lifo));

        return true;
    }
};
