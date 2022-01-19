ListNode *detectCycle(ListNode *head)
{
    map<ListNode *, int> mp;
    ListNode *cur = head;
    while(cur)
    {
        if(mp.find(cur) != mp.end())
            return cur;
        mp[cur] = 1;
        cur = cur->next;
    }
    return NULL;
}