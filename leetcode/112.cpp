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
    /*constexpr*/ inline bool hasPathSum(
        const TreeNode *root,
        int targetSum
    ) const noexcept {
        Stack<const TreeNode *> s{};
        while (root) {
            s.push(root);
            targetSum -= root->val;
            if (root->left)
                root = root->left;
            else
                root = root->right;
        }

        while (!empty(s)) {
            if (targetSum == 0)
                return true;

            const TreeNode *node{};
            do {
                node = s.top();
                targetSum += node->val;
                s.pop();
            } while (!empty(s) && (node == s.top()->right || !s.top()->right));

            if (empty(s))
                break;

            node = s.top()->right;
            do {
                s.push(node);
                targetSum -= node->val;
                if (node->left)
                    node = node->left;
                else
                    node = node->right;
            } while (node);
        }

        return false;
    }
};
