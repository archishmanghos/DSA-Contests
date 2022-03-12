Node *copyRandomList(Node *head){
    if(!head){
        return NULL;
    }
    
    map<Node *, Node *> mp;
    Node *ansHead = new Node(head->val);
    mp[head] = ansHead;
    Node *traverse = ansHead;
    Node *temp = head->next;
    
    while(temp){
        Node *newNode = new Node(temp->val);
        mp[temp] = newNode;
        traverse->next = newNode;
        traverse = traverse->next;
        temp = temp->next;
    }
    
    temp = head;
    traverse = ansHead;
    while(temp){
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    
    return ansHead;
}