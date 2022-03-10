ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *ansList = new ListNode(0);
    ListNode *head = ansList;
    int add = 0;
    while(l1 or l2){
        add /= 10;
        int x1 = (l1 ? l1->val : 0);
        int x2 = (l2 ? l2->val : 0);
        add = x1 + x2 + (add % 10);
        ansList->next = new ListNode(add % 10);
        ansList = ansList->next;
        l1 = (l1 ? l1->next : l1);
        l2 = (l2 ? l2->next : l2);
    }
    add /= 10;
    if(add){
        ansList->next = new ListNode(add);
    }
    
    return head->next;
}