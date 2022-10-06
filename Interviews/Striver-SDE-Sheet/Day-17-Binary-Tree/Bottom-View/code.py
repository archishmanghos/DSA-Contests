class Solution:
    def bottomView(self, root):
        indices, level, ans, q = {}, {}, [], deque()
        q.append(root)
        level[root] = 0

        while q:
            curNode, l = q[0], level[q[0]]
            q.popleft()
            indices[l] = curNode.data
            if curNode.left:
                q.append(curNode.left)
                level[curNode.left] = l - 1
            if curNode.right:
                q.append(curNode.right)
                level[curNode.right] = l + 1

        for key in sorted(indices):
            ans.append(indices[key])

        return ans
