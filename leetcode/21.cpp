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
class Solution {
public:
    constexpr ListNode *mergeTwoLists(
        ListNode *list1,
        ListNode *list2
    ) const noexcept {
        ListNode *result{}, **ptr{&result};
        while (list1 || list2) {
            if (!list1 || (list2 && list1->val > list2->val)) {
                *ptr = list2;
                list2 = list2->next;
            } else {
                *ptr = list1;
                list1 = list1->next;
            }
            ptr = &(*ptr)->next;
        }
        return result;
    }
};
