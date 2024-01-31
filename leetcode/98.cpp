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
private:
    template<class T>
    using Stack = stack<T, vector<T>>;

public:
    inline bool isValidBST(const TreeNode * const root) const noexcept {
        Stack<const TreeNode *> s{};
        s.push(root);
        do {
            const auto treeNode{s.top()};
            s.pop();
            if (treeNode->left) {
                if (treeNode->val <= treeNode->left->val)
                    return false;
                s.push(treeNode->left);
            }
            if (treeNode->right) {
                if (treeNode->val >= treeNode->right->val)
                    return false;
                s.push(treeNode->right);
            }
        } while (!s.empty());
        return true;
    }
};
