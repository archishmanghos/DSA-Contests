ListNode *head;
int n;
Solution(ListNode *head)
{
    this->head = head;
    n = 0;
    ListNode *temp = head;
    while(temp)
    {
        n += 1;
        temp = temp->next;
    }
}

int getRandom()
{
    int i = rand() % n;
    ListNode *ans = head;
    while(i--)
        ans = ans->next;
    return ans->val;
}