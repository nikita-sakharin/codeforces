/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution final {
private:
    static constexpr size_t listSize(const ListNode *listNode) noexcept {
        auto size{0UZ};
        while (listNode) {
            listNode = listNode->next;
            ++size;
        }
        return size;
    }

    static constexpr ListNode *nextNode(ListNode *listNode, size_t n) noexcept {
        for (; n != 0; --n)
            listNode = listNode->next;
        return listNode;
    }

public:
    constexpr ListNode *getIntersectionNode(
        ListNode *headA,
        ListNode *headB
    ) const noexcept {
        const auto sizeA{listSize(headA)}, sizeB{listSize(headB)};
        if (sizeA < sizeB)
            headB = nextNode(headB, sizeB - sizeA);
        else if (sizeB < sizeA)
            headA = nextNode(headA, sizeA - sizeB);
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
