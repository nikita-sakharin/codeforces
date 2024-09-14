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

    static constexpr bool hasRightSibling(
        const TreeNode * const treeNode,
        const TreeNode * const parent
    ) noexcept {
        return parent->right && treeNode == parent->left;
    }

public:
    inline bool hasPathSum(
        const TreeNode *treeNode,
        int targetSum
    ) const noexcept {
        Stack<const TreeNode *> lifo{};
        while (treeNode) {
            lifo.push(treeNode);
            targetSum -= treeNode->val;
            if (treeNode->left)
                treeNode = treeNode->left;
            else
                treeNode = treeNode->right;
        }

        while (!empty(lifo)) {
            const TreeNode *node{lifo.top()->right};
            while (node) {
                lifo.push(node);
                targetSum -= node->val;
                if (node->left)
                    node = node->left;
                else
                    node = node->right;
            }

            if (targetSum == 0)
                return true;

            do {
                node = lifo.top();
                targetSum += node->val;
                lifo.pop();
            } while (!empty(lifo) && !hasRightSibling(node, lifo.top()));
        }

        return false;
    }
};
