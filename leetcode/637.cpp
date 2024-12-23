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
    using dbl = double;

public:
    constexpr vector<dbl> averageOfLevels(
        const TreeNode * const root
    ) const noexcept {
        vector<dbl> result{};
        queue<const TreeNode *> fifo{};
        fifo.push(root);

        do {
            auto sum{0LL};
            auto count{0UZ};
            for (auto length{size(fifo)}; length != 0; --length) {
                const auto treeNode{fifo.front()};
                fifo.pop();
                sum += treeNode->val;
                ++count;
                if (treeNode->left)
                    fifo.push(treeNode->left);
                if (treeNode->right)
                    fifo.push(treeNode->right);
            }
            result.push_back(dbl(sum) / count);
        } while (!empty(fifo));

        return result;
    }
};
