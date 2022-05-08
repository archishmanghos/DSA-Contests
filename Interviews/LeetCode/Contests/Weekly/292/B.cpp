int countNodes(TreeNode *root, unordered_map<TreeNode *, int> &mp){
    if(!root){
        return 0;
    }
    
    int leftNodes = countNodes(root->left, mp);
    int rightNodes = countNodes(root->right, mp);
    int totalNodes = leftNodes + rightNodes + 1;
    mp[root] = totalNodes;
    return totalNodes;
}

int avgTree(TreeNode *root, int &ans, unordered_map<TreeNode *, int> &mp){
    if(!root){
        return 0;
    }
    
    int leftSum = avgTree(root->left, ans, mp);
    int rightSum = avgTree(root->right, ans, mp);
    int totalSum = leftSum + rightSum + root->val;
    int avg = totalSum / mp[root];
    ans += avg == root->val;
    
    return totalSum;
}

int averageOfSubtree(TreeNode *root){
    unordered_map<TreeNode *, int> mp;
    int x = countNodes(root, mp);
    int ans = 0;
    int y = avgTree(root, ans, mp);
    return ans;
}