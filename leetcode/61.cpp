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
    static constexpr pair<ListNode *, size_t> tailElement(
        ListNode *listNode
    ) noexcept {
        if (!listNode)
            return {nullptr, 0};
        size_t result{1};
        while (listNode->next) {
            listNode = listNode->next;
            ++result;
        }
        return {listNode, result};
    }

    static constexpr ListNode *nthElement(
        ListNode *listNode,
        size_t index
    ) noexcept {
        for (; index != 0; --index)
            listNode = listNode->next;
        return listNode;
    }

public:
    constexpr ListNode *rotateRight(
        ListNode *head,
        const int k
    ) const noexcept {
        auto [tail, size] = tailElement(head);
        if (!tail)
            return nullptr;
        tail->next = head;
        tail = nthElement(head, size - size_t(k) % size - 1);
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};
