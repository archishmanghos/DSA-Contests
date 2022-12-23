#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int iToStr(string n) {
        int ans = 0, j = 1;
        while (n.size() > 0) {
            ans += (n.back() - '0') * j;
            j *= 10;
            n.pop_back();
        }

        return ans;
    }
    TreeNode* helper (int l, int r, int dash, string &t) {
        int dashes = 0;
        vector<int> pos;
        for (int i = l ; i <= r; i++) {
            if (t[i] == '-') dashes += 1;
            else {
                if (dashes == dash) pos.push_back(i);
                dashes = 0;
            }
        }

        string s = "";
        for (int i = l; i <= r; i++) {
            if (t[i] == '-') break;
            s += t[i];
        }
        TreeNode *newNode = new TreeNode(iToStr(s));
        if (pos.size() == 2) {
            newNode->left = helper (pos[0], pos[1] - dash - 1, dash + 1, t);
            newNode->right = helper (pos[1], r, dash + 1, t);
        }
        if (pos.size() == 1) {
            newNode->left = helper (pos[0], r, dash + 1, t);
        }

        return newNode;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return helper (0, traversal.size() - 1, 1, traversal);
    }
};