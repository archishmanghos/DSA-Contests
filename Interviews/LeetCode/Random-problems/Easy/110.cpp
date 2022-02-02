int heightAtEachNode(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int heightLeft = heightAtEachNode(root->left);
    int heightRight = heightAtEachNode(root->right);
    if (heightLeft == -1 or heightRight == -1 or abs(heightLeft - heightRight) > 1)
        return -1;

    return 1 + max(heightLeft, heightRight);
}

bool isBalanced(TreeNode *root) {
    int heightOfTree = heightAtEachNode(root);
    return heightOfTree != -1;
}