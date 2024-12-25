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
    constexpr vector<vector<int>> levelOrder(
        const TreeNode * const root
    ) const noexcept {
        vector<vector<int>> result{};
        if (!root)
            return result;

        queue<const TreeNode *> fifo{};
        fifo.push(root);

        do {
            auto length{size(fifo)};
            auto &level{result.emplace_back()};
            level.reserve(length);
            for (; length != 0; --length) {
                const auto treeNode{fifo.front()};
                fifo.pop();
                level.push_back(treeNode->val);
                if (treeNode->left)
                    fifo.push(treeNode->left);
                if (treeNode->right)
                    fifo.push(treeNode->right);
            }
        } while (!empty(fifo));

        return result;
    }
};
