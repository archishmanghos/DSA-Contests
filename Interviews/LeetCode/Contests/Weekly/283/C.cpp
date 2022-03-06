TreeNode *createBinaryTree(vector <vector<int>> &descriptions) {
    unordered_map < int, TreeNode * > mappedNode;
    set<int> notOccur;
    for (auto i: descriptions) {
        if (mappedNode.find(i[1]) != mappedNode.end()) {
            if (mappedNode.find(i[0]) != mappedNode.end()) {
                if (i[2]) {
                    mappedNode[i[0]]->left = mappedNode[i[1]];
                } else {
                    mappedNode[i[0]]->right = mappedNode[i[1]];
                }
            } else {
                TreeNode *newNode = new TreeNode(i[0]);
                mappedNode[i[0]] = newNode;
                if (i[2]) {
                    mappedNode[i[0]]->left = mappedNode[i[1]];
                } else {
                    mappedNode[i[0]]->right = mappedNode[i[1]];
                }
            }
        } else {
            TreeNode *newNode1 = new TreeNode(i[1]);
            mappedNode[i[1]] = newNode1;
            if (mappedNode.find(i[0]) != mappedNode.end()) {
                if (i[2]) {
                    mappedNode[i[0]]->left = mappedNode[i[1]];
                } else {
                    mappedNode[i[0]]->right = mappedNode[i[1]];
                }
            } else {
                TreeNode *newNode = new TreeNode(i[0]);
                mappedNode[i[0]] = newNode;
                if (i[2]) {
                    mappedNode[i[0]]->left = mappedNode[i[1]];
                } else {
                    mappedNode[i[0]]->right = mappedNode[i[1]];
                }
            }
        }
        notOccur.insert(i[1]);
    }

    TreeNode *head = new TreeNode();
    for (auto i: mappedNode) {
        if (notOccur.find(i.first) == notOccur.end()) {
            head = i.second;
        }
    }
    return head;
}