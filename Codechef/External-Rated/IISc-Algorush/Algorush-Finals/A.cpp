#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = LLONG_MAX;

int T, Q, N;
string S;
char C;
const int MOD = 1e9 + 7;
int fact[mxN], invfact[mxN];

int poow(int a, int b, int m = MOD)
{

	int ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans *a) % m;
		b /= 2;
		a = (a *a) % m;
	}
	return ans;
}

int MODinv(int k)
{
	return poow(k, MOD - 2, MOD);
}

void precompute()
{
	fact[0] = fact[1] = 1;
	for(int i = 2; i < mxN; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	invfact[mxN - 1] = MODinv(fact[mxN - 1]);
	
	for(int i = mxN - 2; i >= 0; i--)
	{
		invfact[i] = invfact[i + 1] * (i + 1);
		invfact[i] %= MOD;
	}
}

int nCr(int x, int y)
{
	if(y > x)
		return 0;
	int num = fact[x];
	num *= invfact[y];
	num %= MOD;
	num *= invfact[x - y];
	num %= MOD;
	return num;
}

int add_mod(int a, int b){
	return (a + b) % MOD;
}

int mul_mod(int a, int b){
	return (a *b) % MOD;
}

int sub_mod(int a, int b){
	return (a - b + MOD) % MOD;
}

void solve() {
    
    cin >> S >> Q;
    vector<int> cnt(26, 0);
    for(char c : S) cnt[c - 'a'] += 1;
    int N1 = S.size();

	vector<vector<int>> prefSum(26,vector<int>());

	for(int i = 0; i < 26; i++){
		int newVal = 0;
		for(int j = 1; j <= cnt[i]; j++){
			int comb = nCr(cnt[i], j);
			int tmp = add_mod(newVal, comb);
			newVal = tmp;
			prefSum[i].push_back(newVal);
		}
	}
    
	while(Q--){
		cin >> C >> N;
		if(cnt[C - 'a'] >= N){
			int previ = 0;
			if(N - 2 >= 0)previ = prefSum[C - 'a'][N - 2];
			int combVal = sub_mod(prefSum[C - 'a'].back(), previ);
			int lenth = N1 - cnt[C - 'a'];
			int power = poow(2, lenth);
			int ans = mul_mod(combVal, power);
			cout << ans << '\n';
		} else{
			cout << 0 << '\n';
		}
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    precompute();

    cin >> T;
    while (T--)
        solve();

    return 0;
}

// guest1.sc@iisc.ac.in
// guest1.sc@56783

// guest2.sc@iisc.ac.in
// guest2.sc@786543