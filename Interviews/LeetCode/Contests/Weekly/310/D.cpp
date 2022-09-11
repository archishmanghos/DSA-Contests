struct Node {
	int val;
	Node *left, *right;
	Node(int data) {
		val = data;
		left = right = NULL;
	}
};

int closestPowerOf2(int n) {
	int ans = 1;
	while (n) {
		ans *= 2;
		n >>= 1;
	}

	return ans;
}

Node* build(int l, int r) {
	if (l == r) {
		Node* root = new Node(0);
		return root;
	}

	int mid = l + (r - l) / 2;
	Node* leftTree = build(l, mid);
	Node* rightTree = build(mid + 1, r);
	Node* root = new Node(leftTree->val + rightTree->val);
	root->left = leftTree;
	root->right = rightTree;
	return root;
}

void update(Node* root, int l, int r, int index, int value) {
	if (l == r) {
		root->val = max(root->val, value);
		return;
	}

	int mid = l + (r - l) / 2;
	if (index <= mid) update(root->left, l, mid, index, value);
	else update(root->right, mid + 1, r, index, value);
	root->val = max(root->left->val, root->right->val);
}

int query(Node* root, int l, int r, int lx, int rx) {
	if (l >= lx and r <= rx) return root->val;
	if (r<lx or l>rx) return -1e9;
	int mid = l + (r - l) / 2;
	return max(query(root->left, l, mid, lx, rx), query(root->right, mid + 1, r, lx, rx));
}

int lis(Node* root) {
	if (!root) return -1e9;
	if (!root->left and !root->right) {
		return root->val;
	}

	return max(lis(root->left), lis(root->right));
}

int lengthOfLIS(vector<int>& nums, int k) {
	int n1 = 0;
	for (int i : nums) {
		n1 = max(n1, i);
	}
	int n = closestPowerOf2(n1 - 1);
	Node* root = build(1, n);
	for (int i = 0; i < nums.size(); i++) {
		int l = max(1, nums[i] - k), r = nums[i] - 1;
		int maxLis = 0;
		if (nums[i] > 1) maxLis = query(root, 1, n, l, r);
		update(root, 1, n, nums[i], maxLis + 1);
	}

	return lis(root);
}