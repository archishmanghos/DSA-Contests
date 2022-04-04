ListNode *swapNodes(ListNode *head, int k){
    ListNode *temp1 = head;
    ListNode *temp2 = head;
    int cnt = 0, n;
    while(temp2){
        cnt += 1;
        if(cnt < k){
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }

    temp2 = head;
    n = cnt, cnt = 0;
    while(temp2){
        cnt += 1;
        if(cnt == (n - k + 1)){
            break;
        }
        temp2 = temp2->next;
    }
    
    swap(temp1->val, temp2->val);
    return head;
}