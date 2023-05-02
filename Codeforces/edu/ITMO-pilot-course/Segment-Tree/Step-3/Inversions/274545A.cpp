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
			node->val = 0;
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
			node->val = 1;
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx);
		update(node->right, mid + 1, r, idx);

		node->val = node->left->val + node->right->val;
	}

	int query(Node *node, int l, int r, int lx) {
		if (r < lx) return 0;
		if (l >= lx) return node->val;

		int mid = l + (r - l) / 2;
		return query(node->left, l, mid, lx) + query(node->right, mid + 1, r, lx);
	}
public:
	void build(int n) {
		this->n = n;
		root = build(0, n - 1);
	}

	void update(int idx) {
		update(root, 0, n - 1, idx);
	}

	int query(int l) {
		return query(root, 0, n - 1, l);
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	SegTree st;
	int N; cin >> N; st.build(N);
	for (int i = 0; i < N; i++) {
		int A; cin >> A; st.update(A - 1);
		cout << st.query(A) << ' ';
	}

	return 0;
}