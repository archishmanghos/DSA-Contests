vector<int> sortedNodesInBST(TreeNode *root)
{
    TreeNode *curNode = root;
    vector<int> ans;
    while(curNode != NULL)
    {
        if(curNode->left == NULL)
        {
            ans.push_back(curNode->val);
            curNode = curNode->right;
            continue;
        }

        TreeNode *lastNodeonLeftSubTree = curNode->left;
        while(lastNodeonLeftSubTree->right and lastNodeonLeftSubTree->right != curNode)
            lastNodeonLeftSubTree = lastNodeonLeftSubTree->right;

        if(lastNodeonLeftSubTree->right == curNode)
        {
            ans.push_back(curNode->val);
            lastNodeonLeftSubTree->right = NULL;
            curNode = curNode->right;
        }
        else
        {
            lastNodeonLeftSubTree->right = curNode;
            curNode = curNode->left;
        }
    }
    return ans;
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> a = sortedNodesInBST(root1);
    vector<int> b = sortedNodesInBST(root2);
    vector<int> ans;
    int i = 0, j = 0;
    while(i < a.size() or j < b.size())
    {
        if(i == a.size())
        {
            ans.push_back(b[j]);
            j += 1;
        }
        else if(j == b.size())
        {
            ans.push_back(a[i]);
            i += 1;
        }
        else
        {
            if(a[i] <= b[j])
            {
                ans.push_back(a[i]);
                i += 1;
            }
            else
            {
                ans.push_back(b[j]);
                j += 1;
            }
        }
    }
    return ans;
}