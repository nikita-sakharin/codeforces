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
    constexpr vector<int> preorderTraversal(
        const TreeNode * const root
    ) const noexcept {
        vector<int> result{};
        queue<const TreeNode *> fifo{};
        fifo.push(root);

        do {
            const auto treeNode{fifo.front()};
            fifo.pop();
            if (treeNode) {
                result.push_back(treeNode->val);
                fifo.push(treeNode->left);
                fifo.push(treeNode->right);
            }
        } while (!empty(fifo));

        return result;
    }
};
