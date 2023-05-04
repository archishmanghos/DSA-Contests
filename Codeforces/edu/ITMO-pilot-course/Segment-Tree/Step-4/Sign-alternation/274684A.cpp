#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *left, *right;
	int sum1, sum2;
	Node() {
		left = right = NULL;
		sum1 = sum2 = 0;
	}
};

class SegTree {
	Node *root;
	int n;
	Node* build(int l, int r, vector<int> &a) {
		Node *node = new Node();
		if (l == r) {
			node->sum1 = (l % 2 == 0 ? a[l] : -a[l]);
			node->sum2 = (l % 2 == 0 ? -a[l] : a[l]);
			return node;
		}

		int mid = l + (r - l) / 2;
		node->left = build(l, mid, a);
		node->right = build(mid + 1, r, a);

		node->sum1 = node->left->sum1 + node->right->sum1;
		node->sum2 = node->left->sum2 + node->right->sum2;
		return node;
	}

	void update(Node *node, int l, int r, int idx, int data) {
		if (!node or idx < l or idx > r) return;
		if (l == r and l == idx) {
			node->sum1 = (l % 2 == 0 ? data : -data);
			node->sum2 = (l % 2 == 0 ? -data : data);
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx, data);
		update(node->right, mid + 1, r, idx, data);

		node->sum1 = node->left->sum1 + node->right->sum1;
		node->sum2 = node->left->sum2 + node->right->sum2;
	}

	int query(Node *node, int l, int r, int lx, int rx) {
		if (lx > r or rx < l) return 0;
		if (l >= lx and r <= rx) return (lx % 2 == 0 ? node->sum1 : node->sum2);

		int mid = l + (r - l) / 2;
		return query(node->left, l, mid, lx, rx) + query(node->right, mid + 1, r, lx, rx);
	}
public:
	void build(vector<int> &a) {
		n = a.size();
		root = build(0, n - 1, a);
	}

	void update(int idx, int val) {
		update(root, 0, n - 1, idx, val);
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
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
	st.build(A);

	int M; cin >> M;
	while (M--) {
		int type; cin >> type;
		if (!type) {
			int i, j; cin >> i >> j; i--;
			st.update(i, j);
		} else {
			int l, r; cin >> l >> r; l--, r--;
			cout << st.query(l, r) << '\n';
		}
	}

	return 0;
}