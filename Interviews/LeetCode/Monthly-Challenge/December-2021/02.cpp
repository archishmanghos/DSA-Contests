ListNode *oddEvenList(ListNode *head)
{
    if(head == NULL)
        return head;
    int first = head->val;
    struct ListNode *last = head;
    int N = 0;
    while(last->next != NULL)
    {
        N += 1;
        last = last->next;
    }
    if(last != NULL)
        N += 1;
    if(N < 3)
        return head;
    struct ListNode *traverse = head;
    int cnt = 0;
    while(traverse != NULL)
    {
        cnt += 1;
        if(cnt > N / 2)
            break;
        struct ListNode *temp = traverse->next;
        if(temp->next != NULL)
            traverse->next = temp->next;
        else
            traverse->next = NULL;
        temp->next = NULL;
        last->next = temp;
        struct ListNode *temp2 = head;
        traverse = traverse->next;
        last = last->next;
    }
    return head;
}