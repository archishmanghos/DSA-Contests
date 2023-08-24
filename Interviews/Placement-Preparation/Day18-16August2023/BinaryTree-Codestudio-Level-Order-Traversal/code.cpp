#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> levelOrder(TreeNode<int> * root) {
    vector<int> answer;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int> *it = q.front();
        q.pop();

        answer.push_back(it->data);
        if (it->left) q.push(it->left);
        if (it->right) q.push(it->right);
    }

    return answer;
}
