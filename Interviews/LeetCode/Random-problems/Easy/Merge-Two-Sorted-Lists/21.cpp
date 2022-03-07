ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *newHead = new ListNode();
    ListNode *traverse = newHead;

    while (list1 and list2) {
        if (list1->val <= list2->val) {
            traverse->next = list1;
            list1 = list1->next;
        } else {
            traverse->next = list2;
            list2 = list2->next;
        }

        traverse = traverse->next;
    }
    traverse->next = (list1 ? list1 : list2);
    return newHead->next;
}