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
		if (l == r) return node;

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

	int query(Node *node, int l, int r, int lx, int rx) {
		if (lx > r or rx < l) return 0;
		if (l >= lx and r <= rx) return node->val;

		int mid = l + (r - l) / 2;
		return query(node->left, l, mid, lx, rx) + query(node->right, mid + 1, r, lx, rx);
	}
public:
	void build(int n) {
		this->n = n;
		root = build(0, n - 1);
	}

	void update(int idx) {
		update(root, 0, n - 1, idx);
	}

	int query(int l, int r) {
		return query(root, 0, n - 1, l, r);
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	SegTree st;
	int N; cin >> N;
	st.build(2 * N);
	int hash[N], answer[N];
	memset(hash, -1, sizeof(hash));

	for (int i = 0; i < 2 * N; i++) {
		int A; cin >> A; A--;
		if (hash[A] != -1) {
			answer[A] = st.query(hash[A], i);
			st.update(hash[A]);
			hash[A] = -1;
		} else {
			hash[A] = i;
		}
	}

	for (int i = 0; i < N; i++) cout << answer[i] << ' ';

	return 0;
}