string tree2str(TreeNode* root) {
    if (!root) return "";
    string ans = to_string(root->val);

    string ans1 = "(";
    string leftTree = tree2str(root->left);
    ans1 += leftTree;
    ans1 += ')';
    if (ans1 != "()") ans += ans1;

    string ans2 = "(";
    string rightTree = tree2str(root->right);
    if (rightTree != "") {
        ans2 += rightTree;
        ans2 += ')';
        if (ans1 == "()") ans += ans1;
        ans += ans2;
    }

    return ans;
}