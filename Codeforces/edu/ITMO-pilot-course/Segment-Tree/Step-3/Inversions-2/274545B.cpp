#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left, *right;
	int val;
	Node() {
		left = right = NULL;
		val = 0;
	}
};

class SegTree {
	Node *root;
	int n;
	Node* build(int l, int r) {
		Node *node = new Node();
		if (l == r) {
			node->val = 1;
			return node;
		}

		int mid = l + (r - l) / 2;
		node->left = build(l, mid);
		node->right = build(mid + 1, r);

		node->val = node->left->val + node->right->val;
		return node;
	}

	void update(Node *node, int l, int r, int idx) {
		if (!node or idx < l or idx > r) return;
		if (l == r and l == idx) {
			node->val = 0;
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx);
		update(node->right, mid + 1, r, idx);

		node->val = node->left->val + node->right->val;
	}

	int query(Node *node, int l, int r, int x) {
		if (l == r) return l;

		int mid = l + (r - l) / 2;
		if (node->right->val >= x) {
			return query(node->right, mid + 1, r, x);
		}

		return query(node->left, l, mid, x - node->right->val);
	}
public:
	void build(int n) {
		this->n = n;
		root = build(0, n - 1);
	}

	void update(int idx) {
		update(root, 0, n - 1, idx);
	}

	int query(int x) {
		return query(root, 0, n - 1, x);
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	SegTree st;
	int N; cin >> N; st.build(N);
	int A[N]; for (int i = 0; i < N; i++) cin >> A[i];

	vector<int> answer(N);
	for (int i = N - 1; i >= 0; i--) {
		int idx = st.query(A[i] + 1);
		st.update(idx);
		answer[i] = idx + 1;
	}

	for (int i : answer) cout << i << ' ';
	return 0;
}