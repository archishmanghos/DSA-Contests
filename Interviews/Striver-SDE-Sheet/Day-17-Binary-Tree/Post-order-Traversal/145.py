class Solution:
    def postorder(self, root, ans):
        if not root: return ans

        self.postorder(root.left, ans)
        self.postorder(root.right, ans)
        ans.append(root.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.postorder(root, ans)
        return ans
