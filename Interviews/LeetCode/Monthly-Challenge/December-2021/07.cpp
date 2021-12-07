int countNodes(ListNode *start)
{
    int cnt = -1;
    while(start != NULL)
    {
        cnt += 1;
        start = start->next;
    }
    return cnt;
}
int getDecimalValue(ListNode *head)
{
    int ans = 0, nodes = countNodes(head), power = 1;
    while(nodes--)
        power *= 2;
    while(head != NULL)
    {
        ans += (head->val) * power;
        power >>= 1;
        head = head->next;
    }
    return ans;
}