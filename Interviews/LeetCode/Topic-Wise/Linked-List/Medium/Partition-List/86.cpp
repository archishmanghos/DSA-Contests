ListNode* partition(ListNode* head, int x) {
    if (!head) return NULL;
    vector<ListNode*> nodesLessX, nodesGreaterEqualX;
    ListNode *temp = head;
    while (temp) {
        if (temp->val < x) nodesLessX.push_back(temp);
        else nodesGreaterEqualX.push_back(temp);
        temp = temp->next;
    }

    ListNode* newHead;
    if (nodesLessX.size() > 0) {
        newHead = nodesLessX[0], temp = nodesLessX[0];
        for (int i = 1; i < nodesLessX.size(); i++) {
            temp->next = nodesLessX[i];
            temp = temp->next;
        }
        for (int i = 0; i < nodesGreaterEqualX.size(); i++) {
            temp->next = nodesGreaterEqualX[i];
            temp = temp->next;
        }
        temp->next = NULL;
    } else {
        newHead = nodesGreaterEqualX[0], temp = nodesGreaterEqualX[0];
        for (int i = 1; i < nodesGreaterEqualX.size(); i++) {
            temp->next = nodesGreaterEqualX[i];
            temp = temp->next;
        }
        temp->next = NULL;
    }

    return newHead;
}