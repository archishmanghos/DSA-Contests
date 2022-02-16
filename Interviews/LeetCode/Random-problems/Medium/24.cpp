ListNode *swapPairs(ListNode *head) {
    ListNode *cur = head;
    ListNode *newHead = new ListNode(-1);
    newHead->next = head;
    ListNode *prevSegment = newHead;
    while (true) {
        if (cur and cur->next) {
            ListNode *temp1 = cur->next;
            ListNode *temp2 = temp1->next;
            prevSegment->next = temp1;
            temp1->next = cur;
            cur->next = temp2;
            prevSegment = cur;
            cur = cur->next;
        } else {
            break;
        }

    }
    return newHead->next;
}