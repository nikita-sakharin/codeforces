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
public:
    constexpr ListNode* removeNthFromEnd(
        ListNode * const head,
        int n
    ) const noexcept {
        ListNode *nthPrev{head}, *current{head};
        while (--n >= 0)
            current = current->next;
        if (!current)
            return head->next;
        while (current->next) {
            current = current->next;
            nthPrev = nthPrev->next;
        }
        nthPrev->next = nthPrev->next->next;
        return head;
    }
};
