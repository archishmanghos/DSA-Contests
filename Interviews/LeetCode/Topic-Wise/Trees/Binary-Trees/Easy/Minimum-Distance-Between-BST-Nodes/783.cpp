vector<TreeNode*> v;
void pushIntoStack(TreeNode* root) {
    while (root) {
        v.push_back(root);
        root = root->left;
    }
}
int whatsNext() {
    return v.size() ? v.back()->val : -1;
}
int getNext() {
    TreeNode* next = v.back();
    v.pop_back();
    pushIntoStack(next->right);
    return next->val;
}
int minDiffInBST(TreeNode* root) {
    pushIntoStack(root);
    int start = getNext(), ans = INT_MAX;
    while (whatsNext() != -1) {
        ans = min(ans, abs(start - whatsNext()));
        start = getNext();
    }

    return ans;
}