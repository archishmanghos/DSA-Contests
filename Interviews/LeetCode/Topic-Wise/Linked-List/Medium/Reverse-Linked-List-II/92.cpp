ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<ListNode*> v;
    int count = 1;
    ListNode* attach1 = NULL, *attach2 = NULL, *tempHead = head;
    while (tempHead) {
        if (count == left - 1) attach1 = tempHead;
        if (count == right + 1) attach2 = tempHead;
        if (count >= left and count <= right) {
            v.push_back(tempHead);
        }
        count += 1;
        tempHead = tempHead->next;
    }

    if (!attach1) attach1 = v.back(), v.pop_back();
    ListNode* newHead = (left == 1 ? attach1 : head);
    while (v.size() > 0) {
        attach1->next = v.back();
        attach1 = attach1->next;
        v.pop_back();
    }

    attach1->next = attach2;
    return newHead;
}