bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left and !root->right) return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val);
}