#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(Node* root, int& ans) {
        if (!root)
            return 0;

        int leftChild = dfs(root->left, ans);
        int rightChild = dfs(root->right, ans);
        int sum = root->data + leftChild + rightChild;
        ans = max(ans, sum);
        return sum;
    }
    int findLargestSubtreeSum(Node* root) {
        int ans = -1e9;
        int totalSum = dfs(root, ans);
        return ans;
    }
};