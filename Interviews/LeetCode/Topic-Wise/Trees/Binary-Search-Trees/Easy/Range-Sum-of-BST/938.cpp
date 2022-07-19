int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;

    int ans = 0;
    if (root->val >= low and root->val <= high) {
        ans += root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    } else if (root->val >= low) {
        ans += rangeSumBST(root->left, low, high);
    } else {
        ans += rangeSumBST(root->right, low, high);
    }

    return ans;
}