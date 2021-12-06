ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    bool longer = true;
    ListNode *l11 = l1;
    ListNode *l22 = l2;
    while(l11 != NULL || l22 != NULL)
    {
        int add1, add2;
        if(l11 == NULL)
            add1 = 0;
        else
            add1 = l11->val;
        if(l22 == NULL)
            add2 = 0;
        else
            add2 = l22->val;
        if(l11 == NULL)
            longer = false;
        int add = add1 + add2 + carry;
        carry = (add > 9 ? 1 : 0);
        add = add % 10;
        if(l11 != NULL)
        {
            l11->val = add;
            l11 = l11->next;
        }
        if(l22 != NULL)
        {
            l22->val = add;
            l22 = l22->next;
        }
    }
    if(carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        if(longer)
        {
            ListNode *temp = l1;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        else
        {
            ListNode *temp = l2;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    if(longer)
        return l1;
    else
        return l2;
}