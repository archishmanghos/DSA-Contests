bool pathFromRootToNode(vector<int> &path, TreeNode *root, int &dest)
{
    if(root == NULL)
        return false;
    path.push_back(root->val);
    if(root->val == dest)
        return true;
    bool ifFound1 = pathFromRootToNode(path, root->left, dest);
    bool ifFound2 = pathFromRootToNode(path, root->right, dest);
    if(ifFound1 || ifFound2)
        return true;
    path.pop_back();
    return false;
}
string getDirections(TreeNode *root, int startValue, int destValue)
{
    vector<int> pathFromRootToSource, pathFromRootToDest;
    bool ans1 = pathFromRootToNode(pathFromRootToSource, root, startValue);
    bool ans2 = pathFromRootToNode(pathFromRootToDest, root, destValue);
    int minn = min((int)pathFromRootToSource.size(), (int)pathFromRootToDest.size()), posOflca;

    for(int i = 0; i < minn; i++)
    {
        if(pathFromRootToSource[i] == pathFromRootToDest[i])
            posOflca = i;
        else
            break;
    }

    TreeNode *temp1 = root;
    int i = 1;
    while(temp1 != NULL && i <= posOflca)
    {
        if(temp1->left != NULL && temp1->left->val == pathFromRootToSource[i])
            temp1 = temp1->left;
        else
            temp1 = temp1->right;
        i += 1;
    }

    string firstPath = "";
    if(i < (int)pathFromRootToSource.size())
    {
        int n = pathFromRootToSource.size();
        while(i < n)
        {
            if(temp1 == NULL)
                break;
            if(temp1->left != NULL && temp1->left->val == pathFromRootToSource[i])
                temp1 = temp1->left;
            else
                temp1 = temp1->right;
            i += 1;
            firstPath += 'U';
        }
    }

    TreeNode *temp2 = root;
    i = 1;
    while(temp2 != NULL && i <= posOflca)
    {
        if(temp2->left != NULL && temp2->left->val == pathFromRootToDest[i])
            temp2 = temp2->left;
        else
            temp2 = temp2->right;
        i += 1;
    }

    string secondPath = "";
    if(i < (int)pathFromRootToDest.size())
    {
        int n = pathFromRootToDest.size();
        while(i < n)
        {
            if(temp2 == NULL)
                break;
            if(temp2->left != NULL && temp2->left->val == pathFromRootToDest[i])
            {
                temp2 = temp2->left;
                secondPath += 'L';
            }
            else
            {
                temp2 = temp2->right;
                secondPath += 'R';
            }
            i += 1;
        }
    }
    string ans = firstPath + secondPath;
    return ans;
}