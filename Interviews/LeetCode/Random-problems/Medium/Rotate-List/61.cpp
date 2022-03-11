ListNode *rotateRight(ListNode *head, int k){
        
    if(!head){
        return NULL;
    }
    
    int len = 0;
    ListNode *temp = head;
    while(temp){
        len += 1;
        temp = temp->next;
    }
    
    k %= len;
    if(k == 0){
        return head;
    }
    
    int pos = len - k, cnt = 1;
    temp = head;
    while(cnt < pos){
        temp = temp->next;
        cnt += 1;
    }
    
    ListNode *nextTemp = temp->next;
    ListNode *newTemp = temp;
    while(newTemp->next){
        newTemp = newTemp->next;
    }
    
    temp->next = NULL;
    newTemp->next = head;
    return nextTemp;
}