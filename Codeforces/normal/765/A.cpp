#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, L, A;
vector<string> X(105);

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

string addPaddingOfZeroes(string x, int length)
{
    int n = x.size();
    if(n == length)
        return x;

    for(int i = 1; i <= (length - n); i++)
        x = '0' + x;

    return x;
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
    cin >> N >> L;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A;
    	X[i] = integertobinary(A);
    	X[i] = addPaddingOfZeroes(X[i], L);
    }

    string Y = "";
    for(int j = 0; j < L; j++)
    {
    	int cnt[2] = {0};
    	for(int i = 1; i <= N; i++)
	    	cnt[(X[i][j] - '0') % 2] += 1;
	    if(cnt[0] >= cnt[1])
    		Y += '0';
    	else
    		Y += '1';
    }
    

    cout << binarytointeger(Y) << '\n';
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