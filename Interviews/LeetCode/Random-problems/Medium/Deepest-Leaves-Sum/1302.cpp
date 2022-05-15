int deepestLeavesSum(TreeNode* root) {
    queue<TreeNode *> q;
    q.push(root);
    int ans = 0;
    while(!q.empty()){
        int sz = q.size();
        ans = 0;
        for(int i = 1; i <= sz; i++){
            TreeNode *curNode = q.front();
            q.pop();
            
            ans += curNode->val;
            if(curNode->left){
                q.push(curNode->left);
            }
            if(curNode->right){
                q.push(curNode->right);
            }
        }
    }
    
    return ans;
}