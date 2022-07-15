class Iterator {
    vector<TreeNode*> left, right;
public:
    Iterator() {
        left.clear();
        right.clear();
    }

    int element(bool nextOrBefore) { // nextOrBefore = 0 means left iterator, else right iterator
        TreeNode* getElement;
        if (nextOrBefore) {
            if (right.size()) {
                getElement = right.back();
                right.pop_back();
                pushIntoStack(getElement->left, 1);
            }
        } else {
            if (left.size()) {
                getElement = left.back();
                left.pop_back();
                pushIntoStack(getElement->right, 0);
            }
        }

        return getElement->val;
    }

    void pushIntoStack(TreeNode* root, bool pushDir) { // pushDir = 0 means left, else right
        if (pushDir) {
            while (root) {
                right.push_back(root);
                root = root->right;
            }
        } else {
            while (root) {
                left.push_back(root);
                root = root->left;
            }
        }
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        Iterator obj;
        obj.pushIntoStack(root, 0), obj.pushIntoStack(root, 1);
        int l = obj.element(0), r = obj.element(1);
        while (l < r) {
            int sum = l + r;
            if (sum == k) return true;
            if (sum < k) l = obj.element(0);
            else r = obj.element(1);
        }

        return false;
    }
};