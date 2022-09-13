void reverseInorder(Node* root, vector<int> &ans) {
    if (!root) return;

    reverseInorder(root->right, ans);
    ans.push_back(root->data);
    reverseInorder(root->left, ans);
}

void swapTree(Node* root, int &index, vector<int> &d) {
    if (!root) return;

    swapTree(root->left, index, d);
    swapTree(root->right, index, d);
    root->data = d[index--];
}

void convertToMaxHeapUtil(Node* root) {
    vector<int> decreasing;
    reverseInorder(root, decreasing);
    int index = decreasing.size() - 1;
    swapTree(root, index, decreasing);
}