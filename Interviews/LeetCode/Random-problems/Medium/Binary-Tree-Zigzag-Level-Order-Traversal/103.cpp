vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> bfs;
    bfs.push(root);
    int cur = 0;
    
    while(!bfs.empty()){
        int sz = bfs.size(), j = 0;
        vector<int> temp(sz);
        for(int i = 1; i <= sz; i++){
            TreeNode *curNode = bfs.front();
            bfs.pop();
            if(cur) temp[sz - j++ -1] = curNode->val;
            else temp[j++] = curNode->val;
            if(curNode->left) bfs.push(curNode->left);
            if(curNode->right) bfs.push(curNode->right);
        }
        cur ^= 1;
        ans.push_back(temp);
    }
    
    return ans;
}