class Iterator:
    def __init__(self, __reverse, root):
        self.stInc, self.stDec, self.reverse = [], [], __reverse
        node = root
        if __reverse:
            while node:
                self.stDec.append(node)
                node = node.right
        else:
            while node:
                self.stInc.append(node)
                node = node.left

    def getNext(self) -> int:
        if self.reverse:
            ans, node = self.stDec[-1], self.stDec[-1].left
            self.stDec.pop()
            while node:
                self.stDec.append(node)
                node = node.right
            return ans.val
        else:
            ans, node = self.stInc[-1], self.stInc[-1].right
            self.stInc.pop()
            while node:
                self.stInc.append(node)
                node = node.left
            return ans.val
        return -1

class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        inc, dec = Iterator(False, root), Iterator(True, root)
        i, j = inc.getNext(), dec.getNext()
        while i < j:
            sum = i + j
            if sum == k: return True
            if sum < k: i = inc.getNext()
            else: j = dec.getNext()
    
        return False