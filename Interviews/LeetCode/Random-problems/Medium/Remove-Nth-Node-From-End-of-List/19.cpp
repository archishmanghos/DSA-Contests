ListNode* removeNthFromEnd(ListNode* head, int n) {
    int countNodes = 0;
    ListNode* temp = head;
    while (temp) {
        countNodes += 1;
        temp = temp->next;
    }

    countNodes = countNodes - n;
    if (countNodes == 0) return head->next;
    else {
        temp = head;
        while (countNodes > 1) {
            temp = temp->next;
            countNodes -= 1;
        }

        ListNode* nextPoint = temp->next ? temp->next->next : NULL;
        temp->next = nextPoint;
    }

    return head;
}