#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
	Node *left, *right;
	int pref, suff, seg, sum;
	Node() {
		left = right = NULL;
		pref = suff = seg = sum = 0;
	}
};

class SegTree {
	Node *root;
	int n;
	Node* build(int l, int r, int n, vector<int> &a) {
		Node *node = new Node();
		if (l == r) {
			node->pref = node->suff = node->seg = node->sum = a[l];
			return node;
		}

		int mid = l + (r - l) / 2;
		node->left = build(l, mid, n, a);
		node->right = build(mid + 1, r, n, a);

		node->seg = max(node->left->suff + node->right->pref, max(node->left->seg, node->right->seg));
		node->pref = max(node->left->pref, node->left->sum + node->right->pref);
		node->suff = max(node->right->suff, node->right->sum + node->left->suff);
		node->sum = node->left->sum + node->right->sum;

		return node;
	}

	void update(Node *node, int l, int r, int idx, int val) {
		if (!node or idx < l or idx > r) return;
		if (l == r and l == idx) {
			node->pref = node->suff = node->seg = node->sum = val;
			return;
		}

		int mid = l + (r - l) / 2;
		update(node->left, l, mid, idx, val);
		update(node->right, mid + 1, r, idx, val);

		node->seg = max(node->left->suff + node->right->pref, max(node->left->seg, node->right->seg));
		node->pref = max(node->left->pref, node->left->sum + node->right->pref);
		node->suff = max(node->right->suff, node->right->sum + node->left->suff);
		node->sum = node->left->sum + node->right->sum;
	}
public:
	void build(vector<int> &a) {
		n = a.size();
		root = build(0, n - 1, n, a);
	}

	void update(int idx, int val) {
		update(root, 0, n - 1, idx, val);
	}

	int query() {
		return root->seg;
	}
};

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	SegTree st;
	st.build(A);
	cout << max(0ll, st.query()) << '\n';
	while (M--) {
		int idx, val; cin >> idx >> val;
		st.update(idx, val);
		cout << max(0ll, st.query()) << '\n';
	}

	return 0;
}