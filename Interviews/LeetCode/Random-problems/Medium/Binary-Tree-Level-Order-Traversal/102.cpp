vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> bfs;
    bfs.push(root);
    while(!bfs.empty()){
        int sz = bfs.size();
        vector<int> level(sz);
        for(int i = 1; i <= sz; i++){
            TreeNode *curNode = bfs.front();
            bfs.pop();
            level[i - 1] = curNode->val;
            if(curNode->left) bfs.push(curNode->left);
            if(curNode->right) bfs.push(curNode->right);
        }
        ans.push_back(level);
    }
    
    return ans;
}