class Solution {
public:
	TreeNode* reverseOddLevels(TreeNode* root) {
		vector<vector<TreeNode*>> level;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int sz = q.size();
			vector<TreeNode*> temp(sz);
			for (int i = 0; i < sz; i++) {
				TreeNode* curNode = q.front();
				q.pop();

				temp[i] = curNode;
				if (curNode->left) q.push(curNode->left);
				if (curNode->right) q.push(curNode->right);
			}
			if ((int)level.size() % 2 == 1) {
				reverse(temp.begin(), temp.end());
			}
			level.push_back(temp);
		}

		for (int i = 0; i < level.size() - 1; i++) {
			for (int k = 0; k < level[i].size(); k++) {
				level[i][k]->left = level[i + 1][k * 2];
				level[i][k]->right = level[i + 1][k * 2 + 1];
			}
		}

		return root;
	}
};