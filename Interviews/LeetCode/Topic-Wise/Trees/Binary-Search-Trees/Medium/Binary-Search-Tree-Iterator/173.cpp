TreeNode *root;
stack<TreeNode *> st;
void pushLeft(TreeNode *node){
    while(node){
        st.push(node);
        node = node->left;
    }
}

BSTIterator(TreeNode *root){
    root = root;
    pushLeft(root);
}

int next(){
    TreeNode *ans = st.top();
    st.pop();
    if(ans->right){
        pushLeft(ans->right);
    }
    return ans->val;
}

bool hasNext(){
    return st.size() > 0;
}