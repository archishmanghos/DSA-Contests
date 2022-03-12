int deepestLeavesSum(TreeNode* root) {
    queue<TreeNode *> q;
    q.push(root);
    int ans = root->val;
    
    while(!q.empty()){
        int sz = q.size();
        int sum = 0;
        for(int i = 1; i <= sz; i++){
            TreeNode *curNode = q.front();
            q.pop();
            sum += curNode->val;
            if(curNode->left){
                q.push(curNode->left);
            }
            if(curNode->right){
                q.push(curNode->right);
            }
        }
        ans = sum;
    }
    return ans;
}