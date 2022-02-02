int countNodes(TreeNode *root) {
    if (!root) {
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    TreeNode *curNode = root;
    while (curNode) {
        leftHeight += 1;
        curNode = curNode->left;
    }
    curNode = root;
    while (curNode) {
        rightHeight += 1;
        curNode = curNode->right;
    }

    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}