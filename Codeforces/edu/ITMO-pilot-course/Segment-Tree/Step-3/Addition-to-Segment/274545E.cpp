#include <bits/stdc++.h>
#define int long long
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
		if (l == r) return node;

		int mid = l + (r - l) / 2;
		node->left = build(l, mid);
		node->right = build(mid + 1, r);

		node->val = node->left->val + node->right->val;
		return node;
	}

	void update(Node *node, int l, int r, int idx, int data) {
		if (!node or idx < l or idx > r) return;
		if (l == r and l == idx) {
			node->val += data;
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx, data);
		update(node->right, mid + 1, r, idx, data);

		node->val = node->left->val + node->right->val;
	}

	int query(Node *node, int l, int r, int rx) {
		if (rx < l) return 0;
		if (r <= rx) return node->val;

		int mid = l + (r - l) / 2;
		return query(node->left, l, mid, rx) + query(node->right, mid + 1, r, rx);
	}
public:
	void build(int n) {
		this->n = n;
		root = build(0, n - 1);
	}

	void update(int idx, int val) {
		update(root, 0, n - 1, idx, val);
	}

	int query(int r) {
		return query(root, 0, n - 1, r);
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	SegTree st;
	int N, M; cin >> N >> M;
	st.build(N);

	while (M--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, v; cin >> l >> r >> v;
			st.update(l, v);
			if (r < N) st.update(r, -v);
		} else {
			int idx; cin >> idx;
			cout << st.query(idx) << '\n';
		}
	}

	return 0;
}