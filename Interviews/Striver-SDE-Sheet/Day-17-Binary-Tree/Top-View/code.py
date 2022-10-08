class Solution:
    def topView(self, root):
        level, nodeLevel, q = {}, {}, deque()
        q.append(root)
        nodeLevel[root] = 0
        
        while q:
            curNode, lvl = q[0], nodeLevel[q[0]]
            q.popleft()
            
            if lvl not in level: 
                level[lvl] = curNode.data
            if curNode.left: 
                q.append(curNode.left)
                nodeLevel[curNode.left] = lvl - 1
            if curNode.right: 
                q.append(curNode.right)
                nodeLevel[curNode.right] = lvl + 1
        
        ans = []
        for key in sorted(level):
            ans.append(level[key])
        
        return ans
