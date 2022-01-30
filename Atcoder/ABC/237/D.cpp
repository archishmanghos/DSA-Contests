#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

struct Node {
    int data;
    struct Node *left, *right;

    Node(int input) {
        data = input;
        left = right = NULL;
    }
};

void inorderTraversal(Node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    string S;
    cin >> N >> S;

    Node *root = new Node(0);
    Node *curNode = root;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            curNode->right = NULL;
            curNode->left = new Node(i + 1);
            curNode = curNode->left;
        } else {
            curNode->left = NULL;
            curNode->right = new Node(i + 1);
            curNode = curNode->right;
        }
    }

    inorderTraversal(root);

    return 0;
}