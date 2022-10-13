class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* cur = node->next;
        node->next = cur->next;
        delete cur;
        cur = nullptr;
    }
};