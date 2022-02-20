ListNode *mergeNodes(ListNode *head) {
    ListNode *newHead = new ListNode(0);
    ListNode *cur = newHead;
    int sum = 0;
    while (head) {
        if (head->val == 0) {
            if (sum > 0) {
                ListNode *node = new ListNode(sum);
                cur->next = node;
                cur = cur->next;
                sum = 0;
            }
        } else {
            sum += head->val;
        }
        head = head->next;
    }
    return newHead->next;
}