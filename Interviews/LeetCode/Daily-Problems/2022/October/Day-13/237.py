class Solution:
    def deleteNode(self, node):
        node.val = node.next.val
        cur = node.next
        node.next = cur.next
        del(cur)
        cur = None