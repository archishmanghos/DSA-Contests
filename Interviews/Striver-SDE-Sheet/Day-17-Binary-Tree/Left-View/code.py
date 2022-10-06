def LeftView(root):
    if not root: return []
    ans = []
    dq = deque()
    dq.append(root)

    while dq:
        sz = len(dq)
        for i in range(sz):
            curNode = dq[0]
            dq.popleft()
            if i == 0: ans.append(curNode.data)
            if curNode.left: dq.append(curNode.left)
            if curNode.right: dq.append(curNode.right)

    return ans
