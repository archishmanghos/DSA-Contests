void inorder(TreeNode *root, TreeNode *&prevNode, tuple<TreeNode *, TreeNode *, TreeNode *> &violation) {
    if (!root) {
        return;
    }

    inorder(root->left, prevNode, violation);
    if (prevNode and root->val < prevNode->val) {
        if (!get<0>(violation)) {
            get<0>(violation) = prevNode;
            get<1>(violation) = root;
        } else {
            get<2>(violation) = root;
        }
    }
    prevNode = root;
    inorder(root->right, prevNode, violation);
}

void recoverTree(TreeNode *root) {
    tuple < TreeNode * , TreeNode *, TreeNode * > violation = {NULL, NULL, NULL};
    TreeNode *prevNode = NULL;
    inorder(root, prevNode, violation);
    if (!get<2>(violation)) {
        swap(get<0>(violation)->val, get<1>(violation)->val);
    } else {
        swap(get<0>(violation)->val, get<2>(violation)->val);
    }
}