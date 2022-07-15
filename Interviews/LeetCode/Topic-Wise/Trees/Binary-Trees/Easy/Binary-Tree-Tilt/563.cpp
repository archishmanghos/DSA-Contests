int sumTilt(TreeNode* root, int &ans) {
    if (!root) return 0;
    int leftSum = sumTilt(root->left, ans);
    int rightSum = sumTilt(root->right, ans);
    ans += abs(leftSum - rightSum);
    return root->val + leftSum + rightSum;
}
int findTilt(TreeNode* root) {
    int ans = 0, sum = sumTilt(root, ans);
    return ans;
}