/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution final {
private:
    template<class T>
    using Stack = stack<T, vector<T>>;

public:
    inline Node *flatten(Node * const head) const noexcept {
        if (!head)
            return nullptr;
        Stack<Node *> s{};
        auto current{head};
        while (current->next || current->child || !s.empty()) {
            if (current->child) {
                if (current->next)
                    s.push(current->next);
                current->next = current->child;
                current->next->prev = current;
                current->child = nullptr;
            }
            if (!current->next) {
                current->next = s.top();
                current->next->prev = current;
                s.pop();
            }
            current = current->next;
        }
        return head;
    }
};
