int countNode(ListNode *head)
{
    int cnt = 0;
    while(head != NULL)
    {
        cnt += 1;
        head = head->next;
    }
    return cnt;
}
ListNode *deleteMiddle(ListNode *head)
{
    int cnt = -1;
    ListNode *temp = head;
    int N = countNode(head);

    if(N == 1)
    {
        head = NULL;
        return head;
    }

    while(temp != NULL)
    {
        cnt += 1;
        if(cnt == (N / 2) - 1)
        {
            ListNode *t = temp->next->next;
            temp->next->next = NULL;
            temp->next = t;
            break;
        }
        temp = temp->next;
    }
    return head;
}