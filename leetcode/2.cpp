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
    constexpr ListNode *addTwoNumbers(
        ListNode *l1,
        ListNode *l2
    ) const noexcept {
        ListNode * const result{l1}, * const reserve{l2}, *prev1{};
        auto carry{false};
        for (; l1 && l2; l1 = l1->next, l2 = l2->next) {
            l1->val += l2->val + carry;
            if (l1->val >= 10) {
                l1->val -= 10;
                carry = true;
            } else
                carry = false;
            prev1 = l1;
        }
        if (l2)
            l1 = prev1->next = l2;
        else if (!l1 && carry)
            l1 = prev1->next = reserve;
        for (; l1 && carry; l1 = l1->next) {
            ++l1->val;
            if (l1->val >= 10)
                l1->val = 0;
            else
                carry = false;
            prev1 = l1;
        }
        if (carry) {
            reserve->val = 1;
            reserve->next = nullptr;
            prev1->next = reserve;
        }
        return result;
    }
};
