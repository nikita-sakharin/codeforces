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

    static constexpr auto radix{10};

    static constexpr int initLeaf(
        const TreeNode *treeNode,
        Stack<const TreeNode *> &lifo,
        int number
    ) noexcept {
        do {
            lifo.push(treeNode);
            number = number * radix + treeNode->val;
            if (treeNode->left)
                treeNode = treeNode->left;
            else
                treeNode = treeNode->right;
        } while (treeNode);

        return number;
    }

    static constexpr bool hasRightSibling(
        const TreeNode * const treeNode,
        const TreeNode * const parent
    ) noexcept {
        return treeNode == parent->left && parent->right;
    }

    static constexpr int nextLeaf(
        Stack<const TreeNode *> &lifo,
        int number
    ) noexcept {
        const TreeNode *treeNode{};
        do {
            treeNode = lifo.top();
            lifo.pop();
            number /= radix;
        } while (!empty(lifo) && !hasRightSibling(treeNode, lifo.top()));

        if (!empty(lifo))
            number = initLeaf(lifo.top()->right, lifo, number);

        return number;
    }

public:
    constexpr int sumNumbers(const TreeNode * const root) const noexcept {
        Stack<const TreeNode *> lifo{};
        auto number{initLeaf(root, lifo, 0)}, result{number};

        do {
            number = nextLeaf(lifo, number);
            result += number;
        } while (!empty(lifo));

        return result;
    }
};
