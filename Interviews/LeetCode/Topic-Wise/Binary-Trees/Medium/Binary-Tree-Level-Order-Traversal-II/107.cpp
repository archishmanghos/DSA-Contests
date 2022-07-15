vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> bfs;
    bfs.push(root);
    
    while(!bfs.empty()){
        int sz = bfs.size(), j = 0;
        vector<int> temp(sz);
        for(int i = 1; i <= sz; i++){
            TreeNode *curNode = bfs.front();
            bfs.pop();
            temp[j++] = curNode->val;
            if(curNode->left) bfs.push(curNode->left);
            if(curNode->right) bfs.push(curNode->right);
        }
        ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}