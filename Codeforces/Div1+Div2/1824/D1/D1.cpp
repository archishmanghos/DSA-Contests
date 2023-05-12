#include <bits/stdc++.h>
#define int long long
using namespace std;

// template from jiangly: https://codeforces.com/contest/1824/submission/205086422

using i64 = long long;
template<class T>
T power(T a, i64 b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2)
			res *= a;
	}
	return res;
}

template <typename T>
T inverse(T a, T m) {
	T u = 0, v = 1;
	while (a != 0) {
		T t = m / a;
		m -= t * a;
		u -= t * v;
		std::swap(a, m);
		std::swap(u, v);
	}

	assert(m == 1);
	return u;
}

template<int P>
struct MInt {
	int x;
	constexpr MInt() : x{} {}
	constexpr MInt(i64 x) : x{norm(x % getMod())} {}

	static int Mod;
	constexpr static int getMod() {
		if (P > 0)
			return P;
		return Mod;
	}
	constexpr static void setMod(int Mod_) { Mod = Mod_; }
	constexpr int norm(int x) const {
		if (x < 0)
			x += getMod();

		if (x >= getMod())
			x -= getMod();

		return x;
	}
	constexpr int val() const { return x; }
	explicit constexpr operator int() const { return x; }
	constexpr MInt operator-() const {
		MInt res;
		res.x = norm(getMod() - x);
		return res;
	}
	constexpr MInt inv() const {
		assert(x != 0);
		return MInt(inverse(x, P));
	}
	constexpr MInt &operator*=(MInt rhs) & {
		x = 1LL * x * rhs.x % getMod();
		return *this;
	}
	constexpr MInt &operator+=(MInt rhs) & {
		x = norm(x + rhs.x);
		return *this;
	}
	constexpr MInt &operator-=(MInt rhs) & {
		x = norm(x - rhs.x);
		return *this;
	}
	constexpr MInt &operator/=(MInt rhs) & {
		return *this *= rhs.inv();
	}
	friend constexpr MInt operator*(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res *= rhs;
		return res;
	}
	friend constexpr MInt operator+(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res += rhs;
		return res;
	}
	friend constexpr MInt operator-(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res -= rhs;
		return res;
	}
	friend constexpr MInt operator/(MInt lhs, MInt rhs) {
		MInt res = lhs;
		res /= rhs;
		return res;
	}
	friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
		i64 v;
		is >> v;
		a = MInt(v);
		return is;
	}
	friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
	friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
	friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};

template<>
int MInt<0>::Mod = 1;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

struct Comb {
	int n;
	std::vector<Z> _fac;
	std::vector<Z> _invfac;
	std::vector<Z> _inv;

	Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
	Comb(int n) : Comb() { init(n); }

	void init(int m) {
		if (m <= n) return;
		_fac.resize(m + 1);
		_invfac.resize(m + 1);
		_inv.resize(m + 1);

		for (int i = n + 1; i <= m; i++)
			_fac[i] = _fac[i - 1] * i;

		_invfac[m] = _fac[m].inv();
		for (int i = m; i > n; i--) {
			_invfac[i - 1] = _invfac[i] * i;
			_inv[i] = _invfac[i] * _fac[i - 1];
		}
		n = m;
	}

	Z fac(int m) {
		if (m > n) init(2 * m);
		return _fac[m];
	}
	Z invfac(int m) {
		if (m > n) init(2 * m);
		return _invfac[m];
	}
	Z inv(int m) {
		if (m > n) init(2 * m);
		return _inv[m];
	}
	Z binom(int n, int m) {
		if (n < m || m < 0) return 0;
		return fac(n) * invfac(m) * invfac(n - m);
	}
} comb;

int N, K, U, V, subtree[200200];
vector<int> adj[200200];
constexpr int MOD = 1e9 + 7;

int32_t main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	auto power = [](int a, int b, int m) -> int{
		int answer = 1;
		for (; b; b /= 2, a = (a * a) % m) if (b & 1) answer = (answer * a) % m;

		return answer;
	};

	auto Mint = [&](int a, int b, int m = 1e9 + 7) -> int { // ab^-1 % m
		if (__gcd(b, m) != 1) return (a * b) % m;
		return (a * power(b, m - 2, m)) % m;
	};

	cin >> N >> K;
	for (int i = 1; i <= N - 1; i++) {
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	if (K & 1) {
		cout << 1 << '\n';
		return 0;
	}

	function<void(int, int)> dfs1 = [&](int node, int par) {
		subtree[node] = 1;
		for (int child : adj[node]) {
			if (child != par) {
				dfs1(child, node);
				subtree[node] += subtree[child];
			}
		}
	};

	dfs1(1, -1);
	Z goodIslands = 0;

	function<void(int, int)> dfs2 = [&](int node, int par) {
		goodIslands += comb.binom(N, 2);
		for (int child : adj[node]) {
			if (child != par) {
				goodIslands -= comb.binom(subtree[child], 2);
				dfs2(child, node);
			} else {
				goodIslands -= comb.binom(N - subtree[node], 2);
			}
		}
	};

	dfs2(1, -1);
	Z pairs = comb.binom(N, 2);
	cout << goodIslands / pairs;
	return 0;
}