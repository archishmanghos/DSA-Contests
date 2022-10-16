class Solution {
public:
    ListNode *moveToFront(ListNode *head) {
        ListNode *cur = head, *pre = NULL;
        while (cur->next) {
            pre = cur;
            cur = cur->next;
        }

        if (!pre) return head;
        pre->next = NULL;
        cur->next = head;
        return cur;
    }
};