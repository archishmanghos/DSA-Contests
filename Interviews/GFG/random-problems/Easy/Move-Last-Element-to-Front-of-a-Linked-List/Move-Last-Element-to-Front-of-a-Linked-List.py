class Solution:
    def moveToFront(self, head : Optional['Node']) -> Optional['Node']:
        cur, pre = head, None
        while cur.next:
            pre = cur
            cur = cur.next
        
        if not pre:
            return head
        pre.next = None
        cur.next = head
        return cur