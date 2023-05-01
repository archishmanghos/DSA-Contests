#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left, *right;
	int one;
	Node() {
		left = right = NULL;
		one = 0;
	}
};

class SegTree {
	Node *root;
	int n;
	Node* build(int l, int r, int n, vector<int> &a) {
		Node *node = new Node();
		if (l == r) {
			node->one = a[l] == 1;
			return node;
		}

		int mid = l + (r - l) / 2;
		node->left = build(l, mid, n, a);
		node->right = build(mid + 1, r, n, a);

		node->one = node->left->one + node->right->one;
		return node;
	}

	void update(Node *node, int l, int r, int idx) {
		if (!node or idx < l or idx > r) return;
		if (l == r and l == idx) {
			node->one = 1 - node->one;
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx);
		update(node->right, mid + 1, r, idx);

		node->one = node->left->one + node->right->one;
	}

	int query(Node *node, int l, int r, int count) {
		if (l == r) return l;

		int mid = l + (r - l) / 2;
		if (node->left->one >= count) {
			return query(node->left, l, mid, count);
		}

		return query(node->right, mid + 1, r, count - node->left->one);
	}
public:
	void build(vector<int> &a) {
		n = a.size();
		root = build(0, n - 1, n, a);
	}

	void update(int idx) {
		update(root, 0, n - 1, idx);
	}

	int query(int count) {
		return query(root, 0, n - 1, count);
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
	SegTree st;
	st.build(A);

	while (M--) {
		int type, x; cin >> type >> x;
		if (type == 1) st.update(x);
		else cout << st.query(x + 1) << '\n';
	}
	return 0;
}