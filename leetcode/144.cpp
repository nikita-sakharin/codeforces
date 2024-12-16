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
    constexpr vector<int> preorderTraversal(
        const TreeNode * const root
    ) const noexcept {
        vector<int> result{};
        Stack<const TreeNode *> lifo{};
        lifo.push(root);

        do {
            const auto treeNode{lifo.top()};
            lifo.pop();
            if (treeNode) {
                result.push_back(treeNode->val);
                lifo.push(treeNode->right);
                lifo.push(treeNode->left);
            }
        } while (!empty(lifo));

        return result;
    }
};
