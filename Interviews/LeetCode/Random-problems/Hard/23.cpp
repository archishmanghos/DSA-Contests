ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < lists.size(); i++) {
        ListNode *curNode = lists[i];
        while (curNode) {
            pq.push(curNode->val);
            curNode = curNode->next;
        }
    }

    if (pq.empty()) {
        return NULL;
    }

    ListNode *curNode = new ListNode(pq.top());
    ListNode *ans = curNode;
    pq.pop();
    while (!pq.empty()) {
        curNode->next = new ListNode(pq.top());
        curNode = curNode->next;
        pq.pop();
    }

    return ans;
}