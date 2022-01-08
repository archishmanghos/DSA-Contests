#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int K;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    int n = 1, cnt = 0;
    while(n <= K)
    {
    	n <<= 1;
    	cnt += 1;
    }

    string S = "";
    int x = n - K;
    x = (n / 2) - x + 1;
    int y = 1;
    for(int i = 1; i <= cnt - 1; i++)
    {
    	if(((x + y - 1) / y) % 2 == 1)
			S += '0';
		else
			S += '2';
    	y <<= 1;
    }

    S += '2';
    reverse(S.begin(), S.end());
    cout << S;
    return 0;
}