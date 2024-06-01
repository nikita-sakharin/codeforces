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
    static constexpr size_t listSize(const ListNode *head) noexcept {
        size_t size{0};
        while (head) {
            head = head->next;
            ++size;
        }
        return size;
    }

    static constexpr ListNode **merge(
        ListNode *first,
        ListNode * const middle,
        ListNode * const last,
        ListNode **ptr
    ) noexcept {
        ListNode *second{middle};
        while (first != middle || second != last) {
            if (first == middle
                || (second != last && second->val < first->val)
            ) {
                *ptr = second;
                second = second->next;
            } else {
                *ptr = first;
                first = first->next;
            }
            ptr = &(*ptr)->next;
        }
        *ptr = last;
        return ptr;
    }

    static constexpr ListNode *nextNode(ListNode *listNode, size_t n) noexcept {
        for (; n != 0; --n)
            listNode = listNode->next;
        return listNode;
    }

public:
    constexpr ListNode *sortList(ListNode *head) const noexcept {
        const auto size{listSize(head)}, half{size >> 1};
        size_t width{1};
        while (width < size) {
            auto n{size};
            auto ptr{&head};
            while (n != 0) {
                const auto left{min(width, n)}, right{min(width, n - left)};
                const auto middle{nextNode(*ptr, left)},
                    last{nextNode(middle, right)};
                ptr = merge(*ptr, middle, last, ptr);
                n -= left + right;
            }
            width = width <= half ? width << 1 : size;
        }
        return head;
    }
};
