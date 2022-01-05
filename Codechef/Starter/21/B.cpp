#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

string integertobinary(int x)
{
	string ans = "";
	while(x > 0)
	{
	    ans += (x % 2) + '0';
	    x >>= 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

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
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    int maxx = -INF;
    map<int, int> mp;
    for(int i = 1; i <= N; i++)
    {
    	string binary = integertobinary(A[i]);
    	reverse(binary.begin(), binary.end());
    	int sz = binary.size();
    	maxx = max(maxx, sz);
    	for(int j = 0; j < sz; j++)
    		mp[j] += binary[j] == '1';
    }

    string ans = "";
    for(int i = 0; i < maxx; i++)
    	ans += (mp[i] > 1 ? '1' : '0');
    reverse(ans.begin(), ans.end());

    cout << binarytointeger(ans) << '\n';
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