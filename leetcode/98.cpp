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
    inline bool isValidBST(const TreeNode * const root) const noexcept {
        Stack<tuple<const TreeNode *, int, int>> s{};
        s.emplace(root, numeric_limits<int>::min(), numeric_limits<int>::max());
        do {
            const auto [treeNode, left, right]{s.top()};
            s.pop();
            if (treeNode->val < left || treeNode->val > right)
                return false;
            if (treeNode->left) {
                if (treeNode->val == numeric_limits<int>::min())
                    return false;
                s.emplace(treeNode->left, left, treeNode->val - 1);
            }
            if (treeNode->right) {
                if (treeNode->val == numeric_limits<int>::max())
                    return false;
                s.emplace(treeNode->right, treeNode->val + 1, right);
            }
        } while (!empty(s));
        return true;
    }
};
