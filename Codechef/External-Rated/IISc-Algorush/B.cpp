#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

const ll VAR = 1e5 + 7;

// Debugging

#ifndef ONLINE_JUDGE
#define debug(x)          \
    cerr << #x << "->\n"; \
    show(x);              \
    cerr << '\n';
#else
#define debug(x)
#endif

template <class T>
void show(vector<T> x) {
    for (auto it : x)
        cerr << it << " ";
}
template <class T>
void show(set<T> x) {
    for (auto it : x)
        cerr << it << " ";
}
template <class T>
void show(unordered_set<T> x) {
    for (auto it : x)
        cerr << it << " ";
}
template <class T>
void show(multiset<T> x) {
    for (auto it : x)
        cerr << it << " ";
}
template <class T>
void show(vector<vector<T>> x) {
    for (auto it : x) {
        for (auto i : it)
            cerr << i << " ";
        cerr << '\n';
    }
}
template <class T>
void show(map<T, T> x) {
    for (auto it : x)
        cerr << it.F << " " << it.S << '\n';
}
template <class T>
void show(T x) { cerr << x << " "; }

// Useful Functions

ll gcd(ll a, ll b) {
    if (a == b)
        return a;
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (b > a)
        return gcd(a, b % a);
    if (a > b)
        return gcd(a % b, b);
    return 0;
}
// ll nPr(ll n, ll r,ll MOD) {return ((fact[n] % MOD) / (fact[n - r] % MOD));}
ll power(ll a, ll b, ll MOD) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b & 1) {
            x = (x * y);
            x %= MOD;
        }
        y = (y * y);
        y %= MOD;
        b >>= 1;
    }
    return x;
}
ll add_mod(ll a, ll b, ll MOD) { return (a + b) % MOD; }
ll sub_mod(ll a, ll b, ll MOD) { return (a - b + MOD) % MOD; }
ll mul_mod(ll a, ll b, ll MOD) { return (a * b) % MOD; }
ll InverseEuler(ll n, ll MOD) { return power(n, MOD - 2, MOD); }
// ll C(ll n, ll r, ll MOD) {return (fact[n] * ((InverseEuler(fact[r], MOD) * InverseEuler(fact[n - r], MOD)) % MOD)) % MOD;}

/*-----------------Logic Starts Here-------------------*/

void solve() {

    ll n, k;
    cin >> n >> k;

    ll num = n;

    ll cnt = 0;

    while (num) {
        cnt++;
        num /= 2;
    }

    ll MOD = 1e9 + 7;

    ll ans = 0;

    ll p = 1;

    for (ll i = 0; i < 62; i++) {
        if (n % 2) {
            ll tmp = power(2, mul_mod(cnt, k, MOD), MOD);
            tmp = sub_mod(tmp, 1, MOD);
            ll tmp1 = power(2, cnt, MOD);
            tmp1 = sub_mod(tmp1, 1, MOD);

            tmp = mul_mod(tmp, InverseEuler(tmp1, MOD), MOD);

            ll temp = mul_mod(p, tmp, MOD);

            ans = add_mod(ans, temp, MOD);
        }
        n /= 2;
        p = mul_mod(p, 2, MOD);
    }

    cout << ans;
}

int main() {
    fio
#ifndef ONLINE_JUDGE
        // for getting input
        freopen("input.txt", "r", stdin);
    // for writing output
    freopen("jout.txt", "w", stdout);
    // for error debugging
    freopen("debug.txt", "w", stderr);
#endif
    ll T;
    if (0)
        T = 1;
    else
        cin >> T;
    for (ll i = 0; i < T; i++) {
        // cout << "Case #" << i + 1 << ": ";
        solve();
        // cout << endl;
        cout << '\n';
        cerr << '\n';
    }
    return 0;
}