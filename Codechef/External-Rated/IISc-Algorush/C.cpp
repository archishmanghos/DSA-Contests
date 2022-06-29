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

    ll n;
    cin >> n;

    vector<vector<pair<ll, vector<pair<ll, ll>>>>> adj(n, vector<pair<ll, vector<pair<ll, ll>>>>());

    vector<vector<pair<ll, ll>>> nodesTime(n, vector<pair<ll, ll>>());

    for (ll i = 0; i < n; i++) {
        ll q;
        cin >> q;
        for (ll j = 0; j < q; j++) {
            ll x, y;
            cin >> x >> y;
            nodesTime[i].push_back({x, y});
        }
    }

    ll m;
    cin >> m;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ll q;
        cin >> q;
        vector<pair<ll, ll>> tmp;
        for (ll j = 0; j < q; j++) {
            ll u, v;
            cin >> u >> v;
            tmp.push_back({u, v});
        }

        adj[x].push_back({y, tmp});
        adj[y].push_back({x, tmp});
    }

    ll str, dest;
    cin >> str >> dest;

    str--;
    dest--;

    ll ans = 0;

    for (ll i = 0; i <= 50; i++) {

        bool flag = false;

        for (auto it : nodesTime[str]) {
            if (i >= it.first && i <= it.second) {
                flag = true;
                break;
            }
        }

        if (flag) {

            vector<bool> vis(n, 0);

            queue<ll> q;
            q.push(str);

            while (!q.empty()) {
                ll pnt = q.front();
                q.pop();

                // cerr << pnt << " ";

                if (vis[pnt])
                    continue;

                vis[pnt] = 1;

                for (auto it : adj[pnt]) {
                    if (!vis[it.first]) {
                        bool flag1 = false, flag2 = false;

                        for (auto j : it.second) {
                            if (i >= j.first && i <= j.second) {
                                flag1 = true;
                                break;
                            }
                        }

                        for (auto j : nodesTime[it.first]) {
                            if (i >= j.first && i <= j.second) {
                                flag2 = true;
                                break;
                            }
                        }

                        if (flag1 && flag2)
                            q.push(it.first);
                    }
                }
            }

            if (vis[dest])
                ans++;
        }

        // cerr << '\n';
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