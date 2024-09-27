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
    inline TreeNode *sortedArrayToBST(
        const vector<int> &nums
    ) const noexcept {
        TreeNode *root{};
        Stack<tuple<TreeNode **, size_t, size_t>> lifo{};
        lifo.emplace(&root, 0, size(nums));
        do {
            const auto [parentPtr, first, last]{lifo.top()};
            lifo.pop();
            const auto middle{midpoint(first, last)};
            const auto treeNode{new TreeNode(nums[middle])};
            *parentPtr = treeNode;
            if (first < middle)
                lifo.emplace(&treeNode->left, first, middle);
            if (middle + 1 < last)
                lifo.emplace(&treeNode->right, middle + 1, last);
        } while (!empty(lifo));

        return root;
    }
};
