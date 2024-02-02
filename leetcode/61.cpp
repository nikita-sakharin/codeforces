/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution final {
private:
    static constexpr pair<ListNode *, size_t> listLastElement(
        ListNode *head
    ) noexcept {
        if (!head)
            return {nullptr, 0};
        size_t result{1};
        while (head->next) {
            head = head->next;
            ++result;
        }
        return {head, result};
    }

    static constexpr ListNode *listNthElement(
        ListNode * head,
        size_t index
    ) noexcept {
        for (; index != 0; --index)
            head = head->next;
        return head;
    }

public:
    constexpr ListNode *rotateRight(
        ListNode *head,
        const int k
    ) const noexcept {
        const auto [last, size] = listLastElement(head);
        if (!last)
            return nullptr;
        last->next = head;
        const auto middle = listNthElement(head, size - size_t(k) % size - 1);
        head = middle->next;
        middle->next = nullptr;
        return head;
    }
};
