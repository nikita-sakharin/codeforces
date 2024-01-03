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
    struct Compare final {
    public:
        constexpr bool operator()(
            const ListNode * const lhs,
            const ListNode * const rhs
        ) const noexcept {
            return lhs->val > rhs->val;
        }
    };

public:
    constexpr ListNode *mergeKLists(vector<ListNode *> &lists) const noexcept {
        const auto first{lists.begin()};
        lists.resize(partition(first, lists.end(), identity{}) - first);

        const Compare compare{};
        make_heap(first, lists.end(), compare);

        ListNode *result{}, **ptr{&result};
        while (!lists.empty()) {
            const auto last{lists.end()};
            pop_heap(first, last, compare);
            auto &back{lists.back()};
            *ptr = back;
            ptr = &back->next;
            back = back->next;
            if (back)
                push_heap(first, last, compare);
            else
                lists.pop_back();
        }
        return result;
    }
};
