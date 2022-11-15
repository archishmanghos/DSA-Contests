class Solution {
   public:
    int getHeight(TreeNode* root, bool side) {
        int ans = 0;
        if (side) {
            while (root) {
                root = root->left;
                ans += 1;
            }
        } else {
            while (root) {
                root = root->right;
                ans += 1;
            }
        }

        return ans;
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = getHeight(root, 1), rightHeight = getHeight(root, 0);
        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};