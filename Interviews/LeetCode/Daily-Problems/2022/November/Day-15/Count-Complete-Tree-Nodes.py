class Solution:
    def getHeight(self, root, side) -> int:
        ans = 0
        if side:
            while root:
                root = root.left
                ans += 1
        else:
            while root:
                root = root.right
                ans += 1
        return ans

    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        leftHeight, rightHeight = self.getHeight(
            root, 1), self.getHeight(root, 0)
        if (leftHeight == rightHeight):
            return (1 << leftHeight) - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
