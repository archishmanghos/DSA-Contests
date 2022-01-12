void insert(TreeNode *root, bool &done, int &val)
{
    if(done)
        return;
    if(root == NULL)
        return;

    if(val < root->val)
    {
        if(root->left)
            insert(root->left, done, val);
        else
        {
            TreeNode *newNode = new TreeNode(val);
            root->left = newNode;
            done = true;
            return;
        }
    }
    else
    {
        if(root->right)
            insert(root->right, done, val);
        else
        {
            TreeNode *newNode = new TreeNode(val);
            root->right = newNode;
            done = true;
            return;
        }
    }
}
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if(!root)
    {
        TreeNode *newNode = new TreeNode(val);
        root = newNode;
        return root;
    }
    bool done = false;
    insert(root, done, val);
    return root;
}