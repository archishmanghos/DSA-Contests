#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

int binarytointeger(string x)
{
	int ans = 0, m = 1;
	for(int i = x.size() - 1; i >= 0; i--)
	{
	    ans += (x[i] - '0') * m;
	    m <<= 1;
	}
	return ans;
}

void solve()
{
    int N;
    cin >> N;

    string S = "00000000";
    set<int> ans;
    int cnt = 0;
    while(ans.size() < N){
    	S += "11";
	    do{
	    	ans.insert(binarytointeger(S));
	    } while(next_permutation(S.begin(), S.end()) and ans.size() < N);
    }

    for(int i : ans){
    	cout << i << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}