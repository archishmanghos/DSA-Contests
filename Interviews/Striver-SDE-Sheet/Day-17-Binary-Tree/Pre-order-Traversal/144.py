class Solution:
    def preorder(self, root, ans):
        if not root: return

        ans.append(root.val)
        self.preorder(root.left, ans)
        self.preorder(root.right, ans)

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.preorder(root, ans)
        return ans
