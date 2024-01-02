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
    constexpr ListNode *deleteDuplicates(ListNode *head) const noexcept {
        if (!head)
            return nullptr;
        const auto result{head};
        while (head->next)
            if (head->val == head->next->val)
                head->next = head->next->next;
            else
                head = head->next;
        return result;
    }
};
