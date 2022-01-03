ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int tot = 0;
    while(temp != NULL)
    {
        tot += 1;
        temp = temp->next;
    }
    temp = head;
    n = tot - n + 1;
    int cnt = 1;
    if(n == 1)
    {
        head = head->next;
        return head;
    }
    while(temp != NULL)
    {
        if(cnt == n - 1)
        {
            ListNode *temp1 = temp->next->next;
            temp->next->next = NULL;
            if(!temp1)
                temp->next = NULL;
            else
                temp->next = temp1;
            break;
        }
        cnt += 1;
        temp = temp->next;
    }
    return head;
}