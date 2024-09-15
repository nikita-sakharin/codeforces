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

    static constexpr const int firstLeaf(
        const TreeNode *treeNode,
        Stack<const TreeNode *> &lifo
    ) noexcept {
        auto sum{0};
        while (treeNode) {
            lifo.push(treeNode);
            sum += treeNode->val;
            if (treeNode->left)
                treeNode = treeNode->left;
            else
                treeNode = treeNode->right;
        }
        return sum;
    }

    static constexpr bool hasRightSibling(
        const TreeNode * const treeNode,
        const TreeNode * const parent
    ) noexcept {
        return treeNode == parent->left && parent->right;
    }

    static constexpr const int nextLeaf(
        Stack<const TreeNode *> &lifo
    ) noexcept {
        auto sum{0};
        const TreeNode *treeNode{};
        do {
            treeNode = lifo.top();
            sum -= treeNode->val;
            lifo.pop();
        } while (!empty(lifo) && !hasRightSibling(treeNode, lifo.top()));

        if (!empty(lifo))
            sum += firstLeaf(lifo.top()->right, lifo);

        return sum;
    }

public:
    inline bool hasPathSum(
        const TreeNode *root,
        int targetSum
    ) const noexcept {
        Stack<const TreeNode *> lifo{};
        targetSum -= firstLeaf(root, lifo);

        while (!empty(lifo)) {
            if (targetSum == 0)
                return true;

            targetSum -= nextLeaf(lifo);
        }

        return false;
    }
};
