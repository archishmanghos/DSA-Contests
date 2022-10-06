class Solution:
    def traverse(self, root, ans):
        if not root: return

        self.traverse(root.left, ans)
        ans.append(root.val)
        self.traverse(root.right, ans)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.traverse(root, ans)
        return ans
