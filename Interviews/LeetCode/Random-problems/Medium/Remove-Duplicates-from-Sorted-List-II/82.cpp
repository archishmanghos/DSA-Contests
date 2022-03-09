ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(101);
    dummy->next = head;
    ListNode *traverse = dummy;

    while (traverse) {
        if (traverse->next and traverse->next->next and traverse->next->val == traverse->next->next->val) {
            ListNode *traverseNow = traverse->next;
            while (traverseNow and traverseNow->next and traverseNow->val == traverseNow->next->val) {
                traverseNow = traverseNow->next;
            }
            traverse->next = traverseNow->next;
        } else {
            traverse = traverse->next;
        }
    }

    return dummy->next;
}