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
        Stack<tuple<TreeNode **, size_t, size_t>> s{};
        s.emplace(&root, 0, size(nums));
        do {
            const auto [ptr, first, last]{s.top()};
            s.pop();
            const auto middle{first + ((last - first) >> 1)};
            const auto treeNode{new TreeNode(nums[middle])};
            *ptr = treeNode;
            if (first < middle)
                s.emplace(&treeNode->left, first, middle);
            if (middle + 1 < last)
                s.emplace(&treeNode->right, middle + 1, last);
        } while (!empty(s));

        return root;
    }
};
