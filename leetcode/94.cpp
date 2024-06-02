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
    inline vector<int> inorderTraversal(
        const TreeNode *treeNode
    ) const noexcept {
        vector<int> result{};
        Stack<const TreeNode *> s{};
        while (treeNode || !s.empty()) {
            while (treeNode) {
                s.push(treeNode);
                treeNode = treeNode->left;
            }
            treeNode = s.top();
            s.pop();
            result.push_back(treeNode->val);
            treeNode = treeNode->right;
        }
        return result;
    }
};
