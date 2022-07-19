class Solution {
public:
    void newTree(TreeNode* root, TreeNode* parentNode, pair<TreeNode*, TreeNode*> &p, int key) {
        if (!root) return;
        if (root->val == key) {
            p = {root, parentNode};
            return;
        } else if (root->val < key) {
            newTree(root->right, root, p, key);
        } else {
            newTree(root->left, root, p, key);
        }
    }

    TreeNode* nodeToBeAttached(TreeNode* root) {
        while (root->right) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*, TreeNode*> foundRoot = {NULL, NULL};
        newTree(root, NULL, foundRoot, key);
        if (!foundRoot.first) {
            return root;
        } else {
            TreeNode* findNode = foundRoot.first;
            TreeNode* parentNode = foundRoot.second;
            if (!parentNode) {
                if (!findNode->left and !findNode->right) {
                    return NULL;
                } else if (!findNode->left) {
                    return findNode->right;
                } else if (!findNode->right) {
                    return findNode->left;
                } else {
                    TreeNode* newRoot = nodeToBeAttached(findNode->left);
                    newRoot->right = findNode->right;
                    return findNode->left;
                }
            } else {
                if (parentNode->left == findNode) {
                    if (!findNode->left and !findNode->right) {
                        parentNode->left = NULL;
                        return root;
                    } else if (!findNode->left or !findNode->right) {
                        parentNode->left = (findNode->left ? findNode->left : findNode->right);
                    } else {
                        TreeNode* newRoot = nodeToBeAttached(findNode->left);
                        newRoot->right = findNode->right;
                        parentNode->left = findNode->left;
                    }
                } else {
                    if (!findNode->left and !findNode->right) {
                        parentNode->right = NULL;
                        return root;
                    } else if (!findNode->left or !findNode->right) {
                        parentNode->right = (findNode->left ? findNode->left : findNode->right);
                    } else {
                        TreeNode* newRoot = nodeToBeAttached(findNode->left);
                        newRoot->right = findNode->right;
                        parentNode->right = findNode->left;
                    }
                }
            }
        }

        return root;
    }
};