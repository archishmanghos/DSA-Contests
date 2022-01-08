int cntNodes(ListNode *nodee)
{
    int cnt = 0;
    while(nodee)
    {
        cnt += 1;
        nodee = nodee->next;
    }
    return cnt;
}
int pairSum(ListNode *head)
{
    int n = cntNodes(head);
    int rem = n / 2, cnt = 0;
    vector<long long int> sum(rem, 0);
    int add = 1;
    while(head)
    {
        if(cnt == rem)
        {
            cnt = rem - 1;
            add = -1;
        }
        sum[cnt] += head->val;
        head = head->next;
        cnt += add;
    }
    long long int ans = 0;
    for(int i = 0; i < rem; i++)
        ans = max(ans, sum[i]);
    return ans;
}